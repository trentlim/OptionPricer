#ifndef PAYOFF_H
#define PAYOFF_H

#include "OptionType.h"
#include <cmath>
#include <stdexcept>

class Payoff {
public:
    Payoff(OptionType type, double strike);

    double operator()(double spot) const;

private:
    OptionType type_ {};
    double K_ {};
};

#endif
