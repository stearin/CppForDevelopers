#include <iostream>

#include "../Measurement.hpp"

int main() {
    if (is_alarm(0) || is_alarm(79) || !is_alarm(80) || !is_alarm(100)) {
        std::cerr << "FAIL: alarm boundaries\n";
        return 1;
    }

    return 0;
}
