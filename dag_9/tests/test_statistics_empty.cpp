#include <iostream>
#include <stdexcept>

#include "../Measurement.hpp"

int main() {
    Statistics empty;

    try {
        (void)empty.mean();
    } catch (const std::logic_error&) {
        return 0;
    }

    std::cerr << "FAIL: mean of empty collection was accepted\n";
    return 1;
}
