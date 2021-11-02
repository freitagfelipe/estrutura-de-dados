#include <iostream>
#include <vector>

int bubblesort(std::vector<int> &v) {
    int count {0};
    bool swapped {true};

    while (swapped) {
        swapped = false;
        count += 1;

        for (int i {0}; i < int(v.size()) - 1; ++i) {
            if (v.at(i) > v.at(i + 1)) {
                std::swap(v.at(i), v.at(i + 1));
                swapped = true;
            }
        }
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

    std::cout << bubblesort(v) << std::endl;

    return 0;
}