#pragma once

namespace Behavioral::Visitor::Filesystem::Literals
{
size_t operator"" _bytes( unsigned long long int _byteSize )
{
    return _byteSize;
}

size_t operator"" _kb( unsigned long long int _kiloBytes )
{
    return 1000_bytes * _kiloBytes;
}
size_t operator"" _mb( unsigned long long int _megaBytes )
{
    return 1000_kb * _megaBytes;
}
};  // namespace Behavioral::Visitor::Filesystem::Literals
