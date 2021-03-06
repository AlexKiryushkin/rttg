
#include <iostream>
#include <memory>
#include <string>

#include <rttg/rttg.h>

using TupleT = std::tuple<int, double, std::string>;

int main()
{
    TupleT tuple{ 5, 3.0, "str"};
    for (std::size_t idx{}; idx < std::tuple_size_v<TupleT>; ++idx)
    {
        /**
         * Firstly double all tuple elements
         */
        rttg::visit([](auto && tupleValue) { tupleValue = tupleValue + tupleValue; }, rttg::get(tuple, idx));

        /**
         * Then print changed values
         */
        rttg::visit([](auto && tupleValue) { std::cout << tupleValue << " "; }, rttg::get(tuple, idx));
    }
}
