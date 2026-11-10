#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{20, 80};
    values.reserve(4);
    values.push_back(50);
    values.at(1) = 85;

    std::cout << "Size: " << values.size() << '\n';

    for (int value : values) {
        std::cout << value << ' ';
    }

    std::cout << '\n';

    return 0;
}
