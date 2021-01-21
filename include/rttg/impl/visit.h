
#pragma once

#include <variant>

#include "variant_utils.h"

namespace rttg
{

/**
 * A thin wrapper around std::visit function.
 * Calls callable with real references instead of std::reference_wrapper.
 */
template <class CallableT, class... VariantTs,
          class = std::enable_if_t<(true && ... && IsVariantRefV<VariantTs>)>>
auto visit(CallableT && callable, VariantTs && ... variants)
{
    return std::visit(
        [&callable](auto && value) { return std::invoke(std::forward<CallableT>(callable), value.get()); },
        std::forward<VariantTs>(variants)...);
}

} // namespace rttg
