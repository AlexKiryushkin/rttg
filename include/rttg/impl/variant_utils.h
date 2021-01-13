
#pragma once

namespace rttg
{

/**
 * Metafunction that provides corresponding std::variant type to given std::tuple type
 */
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

/**
 * Type trait that checks whether given type is std::variant of std::refrence_wrapper's
 */
template <class T>
struct IsVariantRef : std::false_type {};

template <class... Ts>
struct IsVariantRef<std::variant<std::reference_wrapper<Ts>...>> : std::true_type {};

template <class T>
inline constexpr bool IsVariantRefV = IsVariantRef<T>::value;

} // namespace rttg
