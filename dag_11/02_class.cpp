#include <iostream>
#include <string>

#include "Collection.hpp"

int main() {
    Collection<int> numbers;
    numbers.add(20);
    numbers.add(80);

    Collection<std::string> names;
    names.add("room");

    std::cout << numbers.size() << ' ' << numbers.at(1) << '\n';
    std::cout << names.at(0) << '\n';

    return 0;
}
