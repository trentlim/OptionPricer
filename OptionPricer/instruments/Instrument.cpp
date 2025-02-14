#include "Instrument.h"

double Instrument::price()
{
    calculate();
    return price_;
}

void Instrument::calculate()
{
    if (!calculated_) {
        perform_calculations();
        calculated_ = true;
    }
}
