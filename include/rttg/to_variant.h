
#pragma once

namespace rttg {

template <class T>
struct ToVariantRef;

template <class T>
using ToVariantRefT = typename ToVariantRef<T>::type;

template <class... T>
struct ToVariantRef<const std::tuple<T...>>
{
    using type = std::variant<std::reference_wrapper<std::add_const_t<T>>...>;
};

template <class... T>
struct ToVariantRef<std::tuple<T...>>
{
    using type = std::variant<std::reference_wrapper<T>...>;
};

} // namespace rttg
