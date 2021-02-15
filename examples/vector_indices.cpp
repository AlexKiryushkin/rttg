
#include <iostream>
#include <string>
#include <vector>

#include <rttg/rttg.h>

using TupleT = std::tuple<std::string, int, std::string, int, std::string, int>;

std::vector<std::size_t> getIterableIndices()
{
    // some non-trivial logic here
    return std::vector<std::size_t>{ 2U, 3U, 0U, 1U };
}

int main()
{
    const TupleT tuple{ "str1", 1, "str2", 2, "str3", 3 };
    for (const auto idx : getIterableIndices())
    {
        rttg::visit([](auto && tupleValue) { std::cout << tupleValue << " "; }, rttg::get(tuple, idx));
    }
}
