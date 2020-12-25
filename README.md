# RunTimeTupleGet
Provides run-time tuple element access. Allows to iterate over tuple elements in a straightforward fashion.

##Example
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
        std::visit([](auto && tupleValue) { std::cout << tupleValue.get() << " "; }, rttg::get(tuple, idx));
    }
}
```
