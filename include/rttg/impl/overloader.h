
#pragma once

namespace rttg
{

/**
 * Agregator of callables with operator()
 */
template <class... CallableTs>
struct Overloader : CallableTs...
{
    using CallableTs::operator()...;
};

/**
 * Class template argument deduction guide
 */
template <class... CallableTs> Overloader(CallableTs ...) -> Overloader<CallableTs...>;

} // namespace rttg
