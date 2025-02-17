#include "VanillaOption.h"
#include "OptionType.h"
#include "Random.h"
#include <memory>

VanillaOption::VanillaOption(OptionType type, double S, double K, double r, double sigma, double T)
    : Option { type, S, K, r, sigma, T }
{
    payoff_ = std::make_shared<VanillaPayoff>(type, K);
}

void VanillaOption::perform_calculations()
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
