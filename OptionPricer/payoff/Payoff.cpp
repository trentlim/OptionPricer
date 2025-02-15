#include "Payoff.h"
#include "Option.h"

Payoff::Payoff(Option::Type type, double strike)
    : type_ { type }
    , K_ { strike }
{
}

double Payoff::operator()(double spot) const
{
    switch (type_) {
    case Option::Type::call:
        return std::max(spot - K_, 0.0);
    case Option::Type::put:
        return std::max(K_ - spot, 0.0);
    default:
        throw std::invalid_argument("Invalid Option Type");
    }
}
