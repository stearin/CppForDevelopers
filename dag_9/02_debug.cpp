#include <iostream>

int total_values() {
    const int values[]{10, 20, 30};
    int total{};

    // Avsiktligt logikfel för felsökningsövningen: rätt summa ska vara 60.
    for (int index{}; index < 2; ++index) {
        total += values[index];
    }

    return total;
}

int main() {
    std::cout << "Total: " << total_values() << '\n';

    return 0;
}
