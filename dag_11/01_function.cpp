#include <iostream>
#include <string>

template <typename T>
T maximum(T first, T second) {
    return first < second ? second : first;
}

int main() {
    std::cout << maximum(3, 7) << '\n';
    std::cout << maximum(1.5, 2.5) << '\n';
    std::cout << maximum(std::string{"apple"}, std::string{"pear"}) << '\n';

    return 0;
}
