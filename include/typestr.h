#pragma once

#include <string>

namespace typestr_detail
{
    template <typename T>
    std::string name()
    {
#if defined(__clang__)
        const std::string signature = __PRETTY_FUNCTION__;
        const std::string marker = "T = ";
        const std::size_t marker_pos = signature.find(marker);
        if (marker_pos == std::string::npos)
            return signature;

        const std::size_t begin = marker_pos + marker.size();
        const std::size_t end = signature.rfind(']');
        return end == std::string::npos || end < begin
                   ? signature
                   : signature.substr(begin, end - begin);
#elif defined(__GNUC__)
        const std::string signature = __PRETTY_FUNCTION__;
        const std::string marker = "T = ";
        const std::size_t marker_pos = signature.find(marker);
        if (marker_pos == std::string::npos)
            return signature;

        const std::size_t begin = marker_pos + marker.size();
        std::size_t end = signature.find(';', begin);
        if (end == std::string::npos)
            end = signature.rfind(']');

        return end == std::string::npos || end < begin
                   ? signature
                   : signature.substr(begin, end - begin);
#elif defined(_MSC_VER)
        const std::string signature = __FUNCSIG__;
        const std::string marker = "typestr_detail::name<";
        const std::size_t marker_pos = signature.find(marker);
        if (marker_pos == std::string::npos)
            return signature;

        const std::size_t begin = marker_pos + marker.size();
        const std::size_t end = signature.rfind(">(void)");
        if (end == std::string::npos || end < begin)
            return signature;

        std::string result = signature.substr(begin, end - begin);
        const char *prefixes[] = {"class ", "struct ", "enum ", "union "};
        for (unsigned int i = 0; i < 4; ++i)
        {
            const std::string prefix = prefixes[i];
            if (result.compare(0, prefix.size(), prefix) == 0)
            {
                result.erase(0, prefix.size());
                break;
            }
        }
        return result;
#else
        return "unknown";
#endif
    }
}

template <typename T>
std::string typestr()
{
    return typestr_detail::name<T>();
}

template <typename T>
std::string typestr(const T &)
{
    return typestr<T>();
}
