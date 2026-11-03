#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <string>

#include "../Measurement.hpp"

int main() {
    for (const std::string bad : {
        "1 80 extra", "abc", "1+20", "1 2.5", "1 20x", "1", ""
    }) {
        bool rejected{};

        try {
            (void)parse_measurement(bad);
        } catch (const std::invalid_argument&) {
            rejected = true;
        }

        if (!rejected) {
            std::cerr << "FAIL: parser accepted bad format: " << bad << '\n';
            return 1;
        }
    }

    return 0;
}
