#include "Random.h"
#include "VanillaOption.h"
#include <cmath>
#include <iostream>

// Calculate the payoff from a European call option
constexpr double call_option_payoff(double S, double K)
{
    return std::max(S - K, 0.0);
}

// Calculate the payoff from a European put option
constexpr double put_option_payoff(double S, double K)
{
    return std::max(K - S, 0.0);
}

// Calculate the price of a European option with Monte Carlo simulation
double monte_carlo_option_pricer(const VanillaOption& vanilla_option, int number_of_simulations, bool isCallOption)
{
    double payoff_sum { 0 };

    const double drift { (vanilla_option.r() - 0.5 * vanilla_option.sigma() * vanilla_option.sigma()) * vanilla_option.T() };
    const double diffusion { vanilla_option.sigma() * sqrt(vanilla_option.T()) };

    for (int i { 0 }; i < number_of_simulations; ++i) {
        double gaussian { Random::get_gaussian(0.0, 1.0) };

        double ST { vanilla_option.S0() * exp(drift + diffusion * gaussian) };
        double payoff { isCallOption ? call_option_payoff(ST, vanilla_option.K()) : put_option_payoff(ST, vanilla_option.K()) };
        payoff_sum += payoff;
    }

    double average_payoff { payoff_sum / number_of_simulations };
    return exp(-vanilla_option.r() * vanilla_option.T()) * average_payoff;
}

int main()
{
    VanillaOption option { 100.0, 100.0, 0.05, 0.2, 1 };

    int number_of_simulations { 100000 };

    double call_price { monte_carlo_option_pricer(option, number_of_simulations, true) };
    double put_price { monte_carlo_option_pricer(option, number_of_simulations, false) };

    std::cout << "European call price: " << call_price << '\n';
    std::cout << "European put price: " << put_price << '\n';

    return 0;
}
