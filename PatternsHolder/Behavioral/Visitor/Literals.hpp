#pragma once

namespace Behavioral::Visitor::Filesystem::Literals
{
size_t operator "" _bytes( size_t _byteSize )
{
    return _byteSize;
}

size_t operator "" _kb( size_t _kiloBytes )
{
    return 1000_bytes * _kiloBytes;
}
size_t operator "" _mb( size_t _megaBytes )
{
    return 1000_kb * _megaBytes;
}
};  // namespace Visitor::Filesystem::Literals
