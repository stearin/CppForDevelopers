#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <string>

#include "../Measurement.hpp"

int main() {
    for (const std::string bad : {"0 20", "1000 20", "1 -1", "1 101"}) {
        bool rejected{};

        try {
            (void)parse_measurement(bad);
        } catch (const std::out_of_range&) {
            rejected = true;
        }

        if (!rejected) {
            std::cerr << "FAIL: parser accepted out-of-range input: " << bad << '\n';
            return 1;
        }
    }

    return 0;
}
