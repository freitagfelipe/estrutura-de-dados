#include <iostream>
#include <vector>

void insertion_sort(std::vector<int> &v) {
    for (int i {1}; i < int(v.size()); ++i) {
        int key = v.at(i);
        int j = i - 1;

        while (j >= 0 && v.at(j) > key) {
            v.at(j + 1) = v.at(j);

            --j;
        }

        v.at(j + 1) = key;
    }
}

int main() {
    std::vector<int> numbers;
    int queries;

    std::cin >> queries;

    for (int i {0}; i < queries; ++i) {
        int command, n;
        
        std::cin >> command >> n;

        if (command == 1) {
            numbers.push_back(n);

            insertion_sort(numbers);
        } else {
            std::cout << numbers.at(n) << std::endl;
        }
    }

    return 0;
}