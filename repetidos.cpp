#include <iostream>
#include <vector>
#include <map>

int repetidos(const std::vector<int> &v) {
    std::map<int, int> aux;
    int count {0};

    for (const int &number : v) {
        if (aux.find(number) == aux.end()) {
            aux[number] = 1;
        } else {
            aux[number] += 1;
        }
    }

    for (const std::pair<int, int> &pair : aux) {
        count += pair.second - 1;
    }

    return count;
}

int main() {
    int size;

    std::cin >> size;

    std::vector<int> v(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> v.at(i);
    }

    std::cout << repetidos(v) << std::endl;

    return 0;
}