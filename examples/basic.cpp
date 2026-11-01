#include "typestr.h"

#include <string>

struct Widget
{
};

int main()
{
    const std::string integer_name = typestr<int>();
    const std::string widget_name = typestr<Widget>();

    if (integer_name.find("int") == std::string::npos)
        return 1;

    if (widget_name.find("Widget") == std::string::npos)
        return 1;

    const Widget widget;
    return typestr(widget).find("Widget") != std::string::npos ? 0 : 1;
}
