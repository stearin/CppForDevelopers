#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <string>

#include "../Measurement.hpp"

int main() {
    for (const std::string line : {"1 80", " 1 80 "}) {
        const Measurement parsed = parse_measurement(line);

        if (parsed.sensor_id != 1 || parsed.value != 80) {
            std::cerr << "FAIL: wrong values from valid parser input\n";
            return 1;
        }
    }

    return 0;
}
