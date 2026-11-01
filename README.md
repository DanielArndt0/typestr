# typestr

A lightweight, header-only type-to-string utility for C++11 and later.

typestr extracts type names from compiler-generated function signatures for diagnostics and experimentation.

## Requirements

- C++11 or later
- CMake 3.16 or later for CMake integration

## Usage

```cpp
#include "typestr.h"

#include <string>

std::string name = typestr<int>();
```

For more examples and API documentation, see [Usage Documentation](docs/usage.md).

## Manual Integration

Download [typestr.h](https://github.com/DanielArndt0/typestr/blob/main/include/typestr.h) from the repository and add it to your project's include directory.

Include the header using `#include "typestr.h"`. No separate compilation is required.

## CMake Integration

typestr can be integrated directly from GitHub using CMake's `FetchContent` module.

Add the following to your project's `CMakeLists.txt`:

```cmake
include(FetchContent)

FetchContent_Declare(
    typestr
    GIT_REPOSITORY https://github.com/DanielArndt0/typestr.git
    GIT_TAG v1.0.0
)

FetchContent_MakeAvailable(typestr)

target_link_libraries(my_target PRIVATE typestr::typestr)
```

Replace `my_target` with your application's CMake target.

If you already have the typestr source directory inside your CMake project, you can add it instead:

```cmake
add_subdirectory(path/to/typestr)
target_link_libraries(my_target PRIVATE typestr::typestr)
```

typestr is header-only and does not require a separately compiled binary.

## Compatibility

typestr requires C++11 or later. Type name formatting depends on GCC, Clang, or MSVC.

## Disclaimer

typestr is developed for educational purposes and experimentation with type representations. Its output is not a portable or stable type identifier.
