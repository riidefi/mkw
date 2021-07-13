"""This module implements symbols file handling."""

import csv


class Symbol:
    """A symbol is an address with a name."""

    def __init__(self, addr, name):
        self.addr = addr
        self.name = name

    def __repr__(self):
        return "%s=0x%08x" % (self.name, self.addr)


class SymbolsList:
    """Simple list of symbols"""

    def __init__(self):
        self._by_name = {}
        self._by_addr = {}

    def __len__(self):
        return len(self._by_addr)

    def __getitem__(self, addr):
        return self._by_addr[addr]

    def get(self, addr):
        """Looks up a symbol by address."""
        return self._by_addr.get(addr)

    def get_by_name(self, name):
        """Looks up a symbol by name."""
        return self._by_name.get(name)

    def __iter__(self):
        """Returns an iterator of all symbols sorted by address."""
        for addr in sorted(self._by_addr):
            yield self._by_addr[addr]

    def put(self, entry):
        """Inserts a symbol into the list."""
        assert isinstance(entry, Symbol)
        self._by_addr[entry.addr] = entry
        self._by_name[entry.name] = entry

    def __setitem__(self, addr, entry):
        if isinstance(entry, str):
            entry = Symbol(addr, entry)
        assert addr == entry.addr
        self.put(entry)

    def read(self, file):
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

    def write(self, file):
        """Writes a symbol list to a file."""
        writer = csv.writer(file, delimiter=" ")
        for sym in self:
            writer.writerow(["0x%08x" % (sym.addr), sym.name])
