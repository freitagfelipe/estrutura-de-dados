#include <iostream>
#include <vector>
#include <set>

int main() {
    int size;

    std::cin >> size;

    std::vector<int> fila(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> fila.at(i);
    }

    std::cin >> size;

    std::set<int> removidos;

    for (int i {0}; i < size; ++i) {
        int num;

        std::cin >> num;

        removidos.insert(num);
    }

    for (const int &indentifier : fila) {
        if (removidos.find(indentifier) == removidos.end()) {
            std::cout << indentifier << " ";
        }
    }

    std::cout << std::endl;

    return 0;
}