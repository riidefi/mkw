import hashlib


def check_hash(content, expected):
    ctx = hashlib.sha1(content)
    digest = ctx.hexdigest()
    print(f"Hash: {digest}")
    return digest.lower() == expected


def format_segment(name, at, at2, want_size, have_size, tag):
    return (
        "%10s: at_src=0x%08x at_dst=0x%08x at_end=0x%08x want=0x%08x have=0x%08x [%s]"
        % (
            name,
            at,
            at2,
            at + want_size,
            want_size,
            have_size,
            tag,
        )
    )
