#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

#include "Option.h"
#include "OptionType.h"

class VanillaOption : public Option {
public:
    VanillaOption(OptionType type, double S, double K, double r, double sigma, double T);

protected:
    void perform_calculations() override;
};

#endif
