#include <iostream>
#include <initializer_list>
#include <stdexcept>

#include "../Measurement.hpp"

int main() {
    for (int value : {-1, 101}) {
        bool rejected{};

        try {
            (void)is_alarm(value);
        } catch (const std::out_of_range&) {
            rejected = true;
        }

        if (!rejected) {
            std::cerr << "FAIL: alarm accepted " << value << '\n';
            return 1;
        }
    }

    return 0;
}
