# typestr Usage

`typestr` extracts a textual type representation from compiler-generated function signatures.

## Template Form

Retrieve the name of a type using a template argument.

```cpp
#include "typestr.h"

#include <iostream>

int main()
{
    std::cout << typestr<int>() << '\n';
    std::cout << typestr<double>() << '\n';
}
```

**Example output:**

```text
int
double
```

## Value Form

Retrieve the type name directly from an object.

```cpp
#include "typestr.h"

#include <iostream>

struct Widget {};

int main()
{
    Widget widget;

    std::cout << typestr(widget) << '\n';
}
```

**Example output:**

```text
Widget
```

The value overload deduces the type from the argument without copying it.

## Type Qualifiers

Use `decltype` with an explicit template argument to preserve type qualifiers.

```cpp
#include "typestr.h"

#include <iostream>

int main()
{
    const int number = 10;

    std::cout << typestr<decltype(number)>() << '\n';
}
```

**Example output:**

```text
const int
```

## Limitations

- Output is compiler-dependent and can differ between GCC, Clang, and MSVC.
- The implementation uses `__PRETTY_FUNCTION__` or `__FUNCSIG__` where available.
- Names are intended for diagnostics and experimentation.
- Type names should not be used for serialization, stable identifiers, or cross-compiler comparisons.
- Unsupported compilers return `unknown`.

The library requires C++11 or later and does not require RTTI.
