
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
