#include "instruments/Option.h"
#include "utils/Random.h"
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
double monte_carlo_option_pricer(const Option& opt, int number_of_simulations, bool is_call)
{
    double payoff_sum { 0 };

    const double drift { (opt.r() - 0.5 * opt.sigma() * opt.sigma()) * opt.T() };
    const double diffusion { opt.sigma() * sqrt(opt.T()) };

    for (int i { 0 }; i < number_of_simulations; ++i) {
        double gaussian { Random::get_gaussian(0.0, 1.0) };

        double ST { opt.S() * exp(drift + diffusion * gaussian) };
        double payoff { is_call ? call_option_payoff(ST, opt.K()) : put_option_payoff(ST, opt.K()) };
        payoff_sum += payoff;
    }

    double average_payoff { payoff_sum / number_of_simulations };
    return exp(-opt.r() * opt.T()) * average_payoff;
}

int main()
{
    Option put { Option::Type::put, 100.0, 100.0, 0.05, 0.2, 1 };
    Option call { Option::Type::call, 100.0, 100.0, 0.05, 0.2, 1 };

    // int number_of_simulations { 100000 };

    // double call_price { monte_carlo_option_pricer(call, number_of_simulations, true) };
    // double put_price { monte_carlo_option_pricer(put, number_of_simulations, false) };

    // std::cout << "European call price: " << call_price << '\n';
    // std::cout << "European put price: " << put_price << '\n';

    std::cout << "European call price: " << call.price() << '\n';
    std::cout << "European put price: " << put.price() << '\n';

    return 0;
}
