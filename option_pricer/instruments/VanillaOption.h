#ifndef VANILLAOPTION_H
#define VANILLAOPTION_H

class VanillaOption {
public:
    VanillaOption(double S0, double K, double r, double sigma, double T)
        : S0_ { S0 }
        , K_ { K }
        , r_ { r }
        , sigma_ { sigma }
        , T_ { T }
    {
    }

    double S0() const { return S0_; }
    double K() const { return K_; }
    double r() const { return r_; }
    double sigma() const { return sigma_; }
    double T() const { return T_; }

private:
    double S0_ {}; // Initial spot price
    double K_ {}; // Strike price
    double r_ {}; // Risk-free rate
    double sigma_ {}; // Volatility
    double T_ {}; // Time to maturity
};

#endif
