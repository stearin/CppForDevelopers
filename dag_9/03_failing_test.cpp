#include <iostream>

bool is_alarm(int value) {
    if (value < 0 || value > 100) {
        throw std::out_of_range{"Value must be 0..100"};
    }

    return value > 80;
}

int main() {
    if (!is_alarm(80)) {
        std::cerr << "FAIL: 80 must trigger the alarm\n";
        return 1;
    }

    return 0;
}
