#include <iostream>
#include <source_location>
#include <string_view>

void log_message(
    std::string_view text,
    std::source_location location = std::source_location::current()
) {
    std::cout << "Caller: " << location.file_name() << ':' << location.line()
              << " | " << location.function_name()
              << " | " << text << '\n';
}

void check_value(int value) {
    if (value < 0 || value > 100) {
        log_message("Rejected: value must be 0..100");
        return;
    }

    log_message("Accepted: value is 0..100");
}

void log_from_body(std::string_view text) {
    // Här fångas platsen i loggfunktionen, inte hos anroparen.
    const auto location = std::source_location::current();

    std::cout << "Inside: " << location.file_name() << ':' << location.line()
              << " | " << location.function_name()
              << " | " << text << '\n';
}

int main() {
    log_message("Starting demo");

    check_value(80);
    check_value(101);

    // Olika anropsrader ger ändå samma plats när current() ligger i kroppen.
    log_from_body("First call");
    log_from_body("Second call");

    log_message("Finished demo");

    return 0;
}
