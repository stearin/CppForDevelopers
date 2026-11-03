#include <iostream>

#include "Measurement.hpp"

int main() {
    std::cout << std::boolalpha;

    for (int value : {0, 79, 80, 100}) {
        std::cout << value << ": " << is_alarm(value) << '\n';
    }

    return 0;
}
