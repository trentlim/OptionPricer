#include "Option.h"
#include "OptionType.h"
#include "Payoff.h"
#include <memory>
#include <stdexcept>

Option::Option(OptionType type, double S, double K, double r, double sigma, double T)
    : type_ { type }
    , S_ { S }
    , K_ { K }
    , r_ { r }
    , sigma_ { sigma }
    , T_ { T }
    , payoff_ { std::make_shared<Payoff>(type, K) }
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

void Option::perform_calculations()
{
    double payoff_sum { 0 };
    const double number_of_simulations { 100000 };

    const double drift { (r_ - 0.5 * sigma_ * sigma_) * T_ };
    const double diffusion { sigma_ * sqrt(T_) };

    for (int i { 0 }; i < number_of_simulations; ++i) {
        double gaussian { Random::get_gaussian(0.0, 1.0) };

        double ST { S_ * exp(drift + diffusion * gaussian) };
        double payoff { (*payoff_)(ST) };
        payoff_sum += payoff;
    }

    double average_payoff { payoff_sum / number_of_simulations };
    price_ = exp(-r_ * T_) * average_payoff;
}
