#include "Payoffs.h"
#include "OptionType.h"
#include <cmath>
#include <stdexcept>

Payoff::Payoff(OptionType type, double strike)
    : type_ { type }
    , K_ { strike }
{
}

VanillaPayoff::VanillaPayoff(OptionType type, double strike)
    : Payoff { type, strike }
{
}

double VanillaPayoff::operator()(double spot) const
{
    using enum OptionType;

    switch (type_) {
    case call:
        return std::max(spot - K_, 0.0);
    case put:
        return std::max(K_ - spot, 0.0);
    default:
        throw std::invalid_argument("Invalid Option Type");
    }
}
