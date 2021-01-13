# RunTimeTupleGet
Provides run-time tuple element access. Allows both iterating over tuple elements in a straightforward fashion and accessing individual elements.

## Build
This project is header-only. Hence, there is no need to build it. To build examples, simply execute the following commands:
	
	$ git clone https://github.com/AlexKiryushkin/rttg
	$ cd rttg/examples
	$ mkdir build && cd build && cmake ..
	$ cmake --build ./

## Language requirements
This project relies on features from C++17 standard. Thus, compiler should support at least C++17.

## License
See the file [LICENSE](LICENSE).

## Example
1. Iterating over elements of tuple
```cpp
#include <iostream>
#include <string>

#include <rttg/rttg.h>

using TupleT = std::tuple<int, double, std::string>;

int main()
{
    const TupleT tuple{ 5, 3.0, "str"};
    for (std::size_t idx{}; idx < std::tuple_size_v<TupleT>; ++idx)
    {
        rttg::visit([](auto && tupleValue) { std::cout << tupleValue << " "; }, rttg::get(tuple, idx));
    }
}
```
2. Accessing individual elements of tuple
```cpp
#include <iostream>
#include <string>

#include <rttg/rttg.h>

using TupleT = std::tuple<int, double, std::string>;

int main()
{
    const TupleT tuple{ 5, 3.0, "str"};

    rttg::invoke([](int tupleValue) mutable { std::cout << tupleValue << " "; }, rttg::get(tuple, 0U));
    rttg::invoke([](std::string tupleValue) { std::cout << tupleValue << " "; }, rttg::get(tuple, 2U));
}
```
