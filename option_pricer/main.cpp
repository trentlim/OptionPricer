#include "instruments/Option.h"
#include "utils/Random.h"
#include <cmath>
#include <iostream>

int main()
{
    Option put { Option::Type::put, 100.0, 100.0, 0.05, 0.2, 1 };
    Option call { Option::Type::call, 100.0, 100.0, 0.05, 0.2, 1 };

    std::cout << "European call price: " << call.price() << '\n';
    std::cout << "European put price: " << put.price() << '\n';

    return 0;
}
