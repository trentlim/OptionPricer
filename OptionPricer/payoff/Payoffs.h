#ifndef PAYOFFS_H
#define PAYOFFS_H

#include "OptionType.h"
#include <cmath>
#include <stdexcept>

class Payoff {
public:
    Payoff(OptionType type, double strike);
    virtual ~Payoff() = default;

    virtual double operator()(double spot) const = 0;

protected:
    OptionType type_ {};
    double K_ {};
};

class VanillaPayoff : public Payoff {
public:
    VanillaPayoff(OptionType type, double strike);
    double operator()(double spot) const override;
};

#endif
