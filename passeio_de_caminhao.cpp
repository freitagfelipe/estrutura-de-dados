#include <iostream>
#include <queue>

int main() {
    std::queue<std::pair<int, int>> gas_stations;
    int n;

    std::cin >> n;

    for (int i {0}; i < n; ++i) {
        int fuel, next_gas_station;

        std::cin >> fuel >> next_gas_station;

        gas_stations.push({fuel, next_gas_station});
    }

    int current_fuel {0}, answer {0}, current_gas_station {0};

    while (!gas_stations.empty()) {
        auto &[fuel, next_gas_station] {gas_stations.front()};

        ++current_gas_station;

        current_fuel += fuel;

        if (current_fuel < next_gas_station) {
            current_fuel = 0;
            answer = current_gas_station;
        } else {
            current_fuel -= next_gas_station;
        }

        gas_stations.pop();
    }

    std::cout << answer << std::endl;

    return 0;
}