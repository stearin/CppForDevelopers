#include <iostream>
#include <map>

#include "Collection.hpp"
#include "Measurement.hpp"

int main() {
    Collection<Measurement> readings;
    readings.add(Measurement{2, 40});
    readings.add(Measurement{1, 20});
    readings.add(Measurement{1, 80});

    std::map<int, Statistics> grouped;

    for (const auto& reading : readings.values()) {
        grouped[reading.sensor_id].add(reading.value);
    }

    for (const auto& [sensor_id, statistics] : grouped) {
        std::cout << sensor_id << ": count=" << statistics.count()
                  << " mean=" << statistics.mean() << '\n';
    }

    return 0;
}
