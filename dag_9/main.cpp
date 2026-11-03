#include <iostream>

#include "Measurement.hpp"

int main() {
    for (int value : {0, 79, 80, 100}) {
        std::cout << value << ": "
                  << (is_alarm(value) ? "Alarm" : "Normal") << '\n';
    }

    try {
        std::cout << is_alarm(101) << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "Rejected\n";
    }

    return 0;
}
