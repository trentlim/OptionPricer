#ifndef OPTION_H
#define OPTION_H

#include "Instrument.h"
#include "Random.h"
#include <cmath>

class Option : public Instrument {
public:
    enum class Type {
        put,
        call,
    };

    Option(Type type, double S, double K, double r, double sigma, double T);

    double S() const { return S_; }
    double K() const { return K_; }
    double r() const { return r_; }
    double sigma() const { return sigma_; }
    double T() const { return T_; }

protected:
    void perform_calculations() override;

private:
    Type type_ {}; // Call or Put

    double S_ {}; // Spot price of underlying
    double K_ {}; // Strike price
    double r_ {}; // Risk-free rate
    double sigma_ {}; // Volatility
    double T_ {}; // Time to maturity
};

#endif
