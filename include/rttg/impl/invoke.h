
#pragma once

#include "overloader.h"
#include "variant_utils.h"

namespace rttg
{

namespace detail
{

/**
 * Empty callable that should be called when non of the provided callables match the arguments.
 * Two specializations for const and non-const operators() of original callable.
 */
template <bool IsCallableNonConst>
struct FallbackEmptyCallable
{
    template <class T>
    void operator()(T, ...) const
    {
    }
};

template <>
struct FallbackEmptyCallable<true>
{
    template <class T>
    void operator()(T, ...)
    {
    }
};

/**
 * Type implicitly convertible to any type. Used only in unevaluated context.
 */
struct ImplicitlyConvertible
{
    template <class T>
    operator T() const;
};

} // namespace detail


/**
 * Calls @callable if it can be called with type hold by @variants, otherwise does nothing.
 */
template <class CallableT, class... VariantTs,
          class = std::enable_if_t<(true && ... && IsVariantRefV<VariantTs>)>>
auto invoke(CallableT && callable, VariantTs && ... variants)
{
    using ConstCallableT = std::add_const_t<std::remove_reference_t<CallableT>>;
    constexpr auto isCallableNonConst = !std::is_invocable_v<ConstCallableT, detail::ImplicitlyConvertible>;

    Overloader compositeCallable{ callable, detail::FallbackEmptyCallable<isCallableNonConst>{} };
    return std::visit(
        [&compositeCallable](auto && value) { return compositeCallable(value.get()); },
        std::forward<VariantTs>(variants)...);
}

} // namespace rttg
