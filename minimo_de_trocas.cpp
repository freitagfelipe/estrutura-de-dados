#include <iostream>
#include <vector>

int selection_sort(std::vector<int> &v) {
    int count {0};
    
    for (int i {0}; i < int(v.size()) - 1; ++i) {
        int min {i};

        for (int j {i + 1}; j < int(v.size()); ++j) {
            if (v.at(j) < v.at(min)) {
                min = j;
            }
        }

        if (min != i) {
            std::swap(v.at(i), v.at(min));

            ++count;
        }
    }

    return count;
}

int main() {
    int size;

    std::cin >> size;

    std::vector<int> numbers(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> numbers.at(i);
    }

    std::cout << selection_sort(numbers) << std::endl;

    return 0;
}