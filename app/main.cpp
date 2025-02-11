#include "Random.h"
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
double monte_carlo_option_pricer(
    double S0,
    double K,
    double r,
    double sigma,
    double T,
    int number_of_simulations,
    bool isCallOption)
{
    double payoff_sum { 0 };

    const double drift { (r - 0.5 * sigma * sigma) * T };
    const double diffusion { sigma * sqrt(T) };

    for (int i { 0 }; i < number_of_simulations; ++i) {
        double gaussian { Random::get_gaussian(0.0, 1.0) };
        
        double ST { S0 * exp(drift + diffusion * gaussian) };
        double payoff { isCallOption ? call_option_payoff(ST, K) : put_option_payoff(ST, K) };
        payoff_sum += payoff;
    }

    double average_payoff { payoff_sum / number_of_simulations };
    return exp(-r * T) * average_payoff;
}

int main()
{
    double S0 { 100.0 }; // Initial spot price
    double K { 100.0 }; // Strike price
    double r { 0.05 }; // Risk-free rate
    double sigma { 0.2 }; // Volatility
    double T { 1 }; // Time to maturity

    int number_of_simulations { 100000 };

    double call_price { monte_carlo_option_pricer(S0, K, r, sigma, T, number_of_simulations, true) };
    double put_price { monte_carlo_option_pricer(S0, K, r, sigma, T, number_of_simulations, false) };

    std::cout << "European call price: " << call_price << '\n';
    std::cout << "European put price: " << put_price << '\n';

    return 0;
}
