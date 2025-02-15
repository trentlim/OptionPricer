#ifndef PAYOFF_H
#define PAYOFF_H

#include "Option.h"
#include <cmath>
#include <stdexcept>

class Payoff {
public:
    Payoff(Option::Type type, double strike)
        : type_ { type }
        , K_ { strike }
    {
    }

    double operator()(double spot) const
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

private:
    Option::Type type_ {};
    double K_ {};
};

#endif
