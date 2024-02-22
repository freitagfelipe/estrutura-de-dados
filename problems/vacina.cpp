#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &v) {
    for (int i {1}; i < int(v.size()); ++i) {
        int key {v.at(i)};
        int j {i - 1};

        while (j >= 0 && v.at(j) > key) {
            v.at(j + 1) = v.at(j);

            --j;
        }

        v.at(j + 1) = key;
    }
}

void vacina(std::vector<int> &patients, std::vector<int> &vaccines) {
    insertion_sort(patients);
    insertion_sort(vaccines);

    for (int i {0}; i < int(patients.size()); ++i) {
        if (patients.at(i) > vaccines.at(i)) {
            std::cout << "No" << std::endl;

            return;
        }
    }

    std::cout << "Yes" << std::endl;
}

int main() {
    int size;

    std::cin >> size;

    std::vector<int> patients(size, 0), vaccines(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> vaccines.at(i);
    }

    for (int i {0}; i < size; ++i) {
        std::cin >> patients.at(i);
    }

    vacina(patients, vaccines);

    return 0;
}