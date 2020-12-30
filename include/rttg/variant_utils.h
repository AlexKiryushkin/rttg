
#pragma once

namespace rttg {

template <class T>
struct ToVariantRef;

template <class T>
using ToVariantRefT = typename ToVariantRef<T>::type;

template <class... Ts>
struct ToVariantRef<const std::tuple<Ts...>>
{
    using type = std::variant<std::reference_wrapper<std::add_const_t<Ts>>...>;
};

template <class... Ts>
struct ToVariantRef<std::tuple<Ts...>>
{
    using type = std::variant<std::reference_wrapper<Ts>...>;
};

template <class T>
struct IsVariantRef : std::false_type {};

template <class... Ts>
struct IsVariantRef<std::variant<std::reference_wrapper<Ts>...>> : std::true_type {};

template <class T>
inline constexpr bool IsVariantRefV = IsVariantRef<T>::value;

} // namespace rttg
