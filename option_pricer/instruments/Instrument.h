#ifndef INSTRUMENT_H
#define INSTRUMENT_H

class Instrument {
public:
    virtual ~Instrument() = default;

    virtual double price()
    {
        calculate();
        return price_;
    }

    virtual void calculate()
    {
        if (!calculated_) {
            perform_calculations();
            calculated_ = true;
        }
    }

protected:
    virtual void perform_calculations() = 0;

    bool calculated_ {};
    double price_ {};

private:
};

#endif
