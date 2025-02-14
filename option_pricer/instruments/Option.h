#ifndef OPTION_H
#define OPTION_H

#include "Instrument.h"
#include "Random.h"
#include <cmath>

class Option : public Instrument {
public:
    enum Type {
        put,
        call,
    };

    Option(Type type, double S, double K, double r, double sigma, double T)
        : type_ { type }
        , S_ { S }
        , K_ { K }
        , r_ { r }
        , sigma_ { sigma }
        , T_ { T }
    {
    }

    double S() const { return S_; }
    double K() const { return K_; }
    double r() const { return r_; }
    double sigma() const { return sigma_; }
    double T() const { return T_; }

protected:
    void perform_calculations() override
    {
        double payoff_sum { 0 };
        const double number_of_simulations { 100000 };

        const double drift { (r_ - 0.5 * sigma_ * sigma_) * T_ };
        const double diffusion { sigma_ * sqrt(T_) };

        for (int i { 0 }; i < number_of_simulations; ++i) {
            double gaussian { Random::get_gaussian(0.0, 1.0) };

            double ST { S_ * exp(drift + diffusion * gaussian) };
            double payoff { type_ ? std::max(ST - K_, 0.0) : std::max(K_ - ST, 0.0) };
            payoff_sum += payoff;
        }

        double average_payoff { payoff_sum / number_of_simulations };
        price_ = exp(-r_ * T_) * average_payoff;
    }

private:
    Type type_ {}; // Call or Put

    double S_ {}; // Spot price of underlying
    double K_ {}; // Strike price
    double r_ {}; // Risk-free rate
    double sigma_ {}; // Volatility
    double T_ {}; // Time to maturity
};

#endif
