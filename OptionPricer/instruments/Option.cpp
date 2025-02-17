#include "Option.h"
#include "OptionType.h"
#include <stdexcept>

Option::Option(OptionType type, double S, double K, double r, double sigma, double T)
    : type_ { type }
    , S_ { S }
    , K_ { K }
    , r_ { r }
    , sigma_ { sigma }
    , T_ { T }
{
    if (S <= 0.0)
        throw std::invalid_argument("Underlying price S must be greater than 0.");
    if (K <= 0.0)
        throw std::invalid_argument("Strike price K must be greater than 0.");
    if (sigma <= 0.0)
        throw std::invalid_argument("Volatility sigma must be greater than 0.");
    if (T <= 0.0)
        throw std::invalid_argument("Time to maturity T must be greater than 0.");
}
