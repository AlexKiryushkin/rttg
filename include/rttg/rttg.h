#pragma once

#include <functional>
#include <stdexcept>
#include <tuple>
#include <variant>

#include "to_variant.h"

namespace rttg
{

namespace detail {

template <std::size_t FirstIdx, std::size_t LastIdx, class TupleTRef, 
          class TupleT = std::remove_reference_t<TupleTRef>, 
          class ReturnT = ToVariantRefT<TupleT> >
ReturnT binaryGetImpl(TupleTRef && tuple, std::size_t index)
{
    constexpr auto MiddleIdx = (FirstIdx + LastIdx) / 2;
    if constexpr (FirstIdx == LastIdx)
    {
        return ReturnT{ std::in_place_index_t<MiddleIdx>{}, std::ref(std::get<MiddleIdx>(tuple)) };
    }
    else
    {
        if constexpr (MiddleIdx > 0)
        {
            if (MiddleIdx > index)
            {
                return binaryGetImpl<FirstIdx, MiddleIdx - 1>(std::forward<TupleTRef>(tuple), index);
            }
        }

        if (MiddleIdx < index)
        {
            return binaryGetImpl<MiddleIdx + 1, LastIdx>(std::forward<TupleTRef>(tuple), index);
        }

        return ReturnT{ std::in_place_index_t<MiddleIdx>{}, std::ref(std::get<MiddleIdx>(tuple)) };
    }
}

} // namespace detail

template <class TupleTRef, class TupleT = std::remove_reference_t<TupleTRef>, class ReturnT = ToVariantRefT<TupleT> >
ReturnT get(TupleTRef && tuple, std::size_t index)
{
    if (index >= std::tuple_size_v<TupleT>)
    {
        throw std::out_of_range("Error! Tuple index is out of range!\n");
    }

    return detail::binaryGetImpl<0, std::tuple_size_v<TupleT> - 1>(std::forward<TupleTRef>(tuple), index);
}

} // namespace rttg

