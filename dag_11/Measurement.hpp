#ifndef COURSE_MEASUREMENT_HPP
#define COURSE_MEASUREMENT_HPP

#include <algorithm>
#include <charconv>
#include <sstream>
#include <stdexcept>
#include <string>

struct Measurement {
    int sensor_id;
    int value;
};

inline Measurement parse_measurement(const std::string& line) {
    std::istringstream input{line};
    std::string id_token;
    std::string value_token;
    std::string extra;

    if (!(input >> id_token >> value_token) || (input >> extra)) {
        throw std::invalid_argument{"Expected two integers"};
    }

    int sensor_id{};
    int value{};

    const auto id_result = std::from_chars(
        id_token.data(), id_token.data() + id_token.size(), sensor_id);

    const auto value_result = std::from_chars(
        value_token.data(), value_token.data() + value_token.size(), value);

    if (id_result.ec != std::errc{} ||
        id_result.ptr != id_token.data() + id_token.size() ||
        value_result.ec != std::errc{} ||
        value_result.ptr != value_token.data() + value_token.size()) {
        throw std::invalid_argument{"Expected two integers"};
    }

    if (sensor_id < 1 || sensor_id > 999 || value < 0 || value > 100) {
        throw std::out_of_range{"ID must be 1..999; value must be 0..100"};
    }

    return Measurement{sensor_id, value};
}

inline bool is_alarm(int value) {
    if (value < 0 || value > 100) {
        throw std::out_of_range{"Value must be 0..100"};
    }

    return value >= 80;
}

class Statistics {
public:
    void add(int value) {
        if (value < 0 || value > 100) {
            throw std::out_of_range{"Value must be 0..100"};
        }

        if (count_ >= max_records) {
            throw std::length_error{"Too many measurements"};
        }

        ++count_;
        sum_ += value;
        minimum_ = std::min(minimum_, value);
        maximum_ = std::max(maximum_, value);
    }

    long long count() const {
        return count_;
    }

    long long sum() const {
        return sum_;
    }

    int minimum() const {
        require_data();
        return minimum_;
    }

    int maximum() const {
        require_data();
        return maximum_;
    }

    double mean() const {
        require_data();
        return static_cast<double>(sum_) / count_;
    }

    static constexpr long long max_records{20'000'000};

private:
    void require_data() const {
        if (count_ == 0) {
            throw std::logic_error{"No measurements"};
        }
    }

    long long count_{};
    long long sum_{};
    int minimum_{100};
    int maximum_{};
};

#endif
