#ifndef MONTECARLO_H
#define MONTECARLO_H

#include "instruments/VanillaOption.h"

class MonteCarlo {
public:
    MonteCarlo(const VanillaOption& opt, int number_of_simulations, bool is_call);

    double price() const;

private:
    VanillaOption opt;
    int number_of_simulations {};
    bool is_call {};
};

#endif
