#include <iostream>

#include "../Measurement.hpp"

int main() {
    Statistics statistics;
    statistics.add(0);
    statistics.add(100);

    if (statistics.count() != 2 || statistics.sum() != 100 ||
        statistics.minimum() != 0 || statistics.maximum() != 100 ||
        statistics.mean() != 50.0) {
        std::cerr << "FAIL: incorrect statistics for 0 and 100\n";
        return 1;
    }

    return 0;
}
