#include "OptionType.h"
#include "VanillaOption.h"
#include <iostream>

int main()
{
    VanillaOption put { OptionType::put, 100.0, 100.0, 0.05, 0.2, 1 };
    VanillaOption call { OptionType::call, 100.0, 100.0, 0.05, 0.2, 1 };

    std::cout << "European call price: " << call.price() << '\n';
    std::cout << "European put price: " << put.price() << '\n';

    return 0;
}
