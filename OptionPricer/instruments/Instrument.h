#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Instrument {
public:
    virtual ~Instrument() = default;

    // Get the price of the instrument
    double price();

    // Calculate the price of the instrument
    // Calls perform_calculations() if not yet calculated
    void calculate();

protected:
    virtual void perform_calculations() = 0;

    bool calculated_ {};
    double price_ {};
};

#endif
