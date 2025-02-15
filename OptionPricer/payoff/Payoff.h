#ifndef PAYOFF_H
#define PAYOFF_H

#include "Option.h"
#include <cmath>
#include <stdexcept>

class Payoff {
public:
    Payoff(Option::Type type, double strike);

    double operator()(double spot) const;

private:
    Option::Type type_ {};
    double K_ {};
};

#endif
