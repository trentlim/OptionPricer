#include "Payoff.h"
#include "OptionType.h"

Payoff::Payoff(OptionType type, double strike)
    : type_ { type }
    , K_ { strike }
{
}

double Payoff::operator()(double spot) const
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
