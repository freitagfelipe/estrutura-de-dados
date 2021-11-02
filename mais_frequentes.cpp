#include <iostream>
#include <vector>
#include <map>

std::pair<int, int> mais_frequente(const std::vector<int> &v) {
    std::map<int, int> aux;

    for (const int &number : v) {
        if (aux.find(number) == aux.end()) {
            aux[number] = 1;
        } else {
            aux[number] += 1;
        }
    }

    std::pair<int, int> highest {*aux.begin()};

    for (const std::pair<int, int> &pair : aux) {
        if (pair.second >= highest.second) {
            highest = pair;
        }
    }

    return highest;
}

int main() {
    int size;

    std::cin >> size;

    std::vector<int> v(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> v.at(i);
    }

    std::pair<int, int> answer = mais_frequente(v);

    std::cout << answer.first << " " << answer.second << std::endl;

    return 0;
}