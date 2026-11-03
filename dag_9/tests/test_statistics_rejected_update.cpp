#include <iostream>
#include <stdexcept>

#include "../Measurement.hpp"

int main() {
    Statistics statistics;
    statistics.add(0);
    statistics.add(100);

    bool rejected{};

    try {
        statistics.add(101);
    } catch (const std::out_of_range&) {
        rejected = true;
    }

    if (!rejected) {
        std::cerr << "FAIL: invalid update was accepted\n";
        return 1;
    }

    if (statistics.count() != 2 || statistics.sum() != 100 ||
        statistics.minimum() != 0 || statistics.maximum() != 100 ||
        statistics.mean() != 50.0) {
        std::cerr << "FAIL: rejected update changed statistics\n";
        return 1;
    }

    return 0;
}
