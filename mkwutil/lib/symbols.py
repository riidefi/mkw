"""This module implements symbols file handling."""

from bisect import bisect_left
import csv


class Symbol:
    """A symbol is an address with a name."""

    def __init__(self, addr, name, size=None):
        self.addr = addr
        self.name = name
        self.size = size

    def __repr__(self):
        return "%s=0x%08x" % (self.name, self.addr)

    def slice(self):
        """Returns a slice object for address range occupied by the symbol."""
        assert self.size is not None
        return slice(self.addr, self.addr + self.size)

    def __copy__(self):
        return type(self)(self.addr, self.name, self.size)


class SymbolsList:
    """Simple list of symbols"""

    def __init__(self):
        self._by_name = {}
        self._by_addr = {}

    def __len__(self):
        return len(self._by_addr)

    def __getitem__(self, addr):
        return self._by_addr[addr]

    def __contains__(self, key):
        return (key in self._by_addr) or (key in self._by_name)

    def get(self, addr):
        """Looks up a symbol by address."""
        return self._by_addr.get(addr)

    def get_by_name(self, name):
        """Looks up a symbol by name."""
        return self._by_name.get(name)

    def __iter__(self):
        """Returns an iterator of all symbols sorted by address."""
        return self.items()

    def items(self, start=0, stop=-1):
        """Returns an iterator of all symbols sorted by address with bounds by address."""
        sorted_by_addr = sorted(self._by_addr)
        if start > 0:
            # Binary search to determine first symbol with address >= start.
            sorted_by_addr = sorted_by_addr[bisect_left(sorted_by_addr, start) :]
        for addr in sorted_by_addr:
            if stop > 0 and stop <= addr:
                break
            yield self._by_addr[addr]

    def slice(self, start=0, stop=-1):
        """Returns a symbol list with bounds by address."""
        new_list = SymbolsList()
        for sym in self.items(start, stop):
            new_list.put(sym)
        return new_list

    def put(self, entry):
        """Inserts a symbol into the list."""
        assert isinstance(entry, Symbol)
        if entry.name in self._by_name:
            print("[WARNING] Duplicate symbol %x %s" % (entry.addr, entry.name))
        self._by_addr[entry.addr] = entry
        self._by_name[entry.name] = entry

    def __setitem__(self, addr, entry):
        if isinstance(entry, str):
            entry = Symbol(addr, entry)
        assert addr == entry.addr
        self.put(entry)

    def __delitem__(self, key):
        if isinstance(key, int):
            sym = self._by_addr.pop(key)
        elif isinstance(key, Symbol):
            sym = self._by_addr.pop(key.addr)
        elif isinstance(key, str):
            sym = self._by_name.pop(key)
            self._by_addr.pop(sym.addr)
            return
        else:
            assert False, "invalid key"
        assert sym is not None
        del self._by_name[sym.name]

    def read_from(self, file):
        """Reads a symbol list from a file."""
        reader = csv.reader(file, delimiter=" ")
        for row in reader:
            if len(row) == 0:
                continue
            assert len(row) == 2
            addr = int(row[0].strip(), 16)
            assert 0 <= addr <= 0xFFFFFFFF
            name = row[1].strip()
            assert name != ""
            self[addr] = name

    def write_to(self, file):
        """Writes a symbol list to a file."""
        writer = csv.writer(file, delimiter=" ")
        for sym in self:
            writer.writerow(["0x%08x" % (sym.addr), sym.name])

    def derive_sizes(self, stop):
        """Fills in sizes of each symbol."""
        addrs = list(self._by_addr.keys())
        for i, addr in enumerate(addrs):
            if i >= len(addrs) - 1:
                sym_stop = stop
            else:
                sym_stop = self._by_addr[addrs[i + 1]].addr
            self._by_addr[addr].size = sym_stop - self._by_addr[addr].addr

    def get_or_default(self, addr):
        sym = self.get(addr)
        if sym:
            return sym
        sym = Symbol(addr, "unk_%08x" % (addr))
        self.put(sym)
        return sym
