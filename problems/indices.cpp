#include <iostream>
#include <vector>
#include <map>

void indices(std::vector<int> &v) {
    std::map<int, int> answer;

    for (int i {0}; i < int(v.size()); ++i) {
        answer[v.at(i)] = i;
    }

    for (int i {1}; i < int(v.size()); ++i) {
        int key {v.at(i)};
        int j {i - 1};

        while (j >= 0 && v.at(j) > key) {
            v.at(j + 1) = v.at(j);

            --j;
        }

        v.at(j + 1) = key;
    }

    for (int i {0}; i < int(v.size()); ++i) {
        if (i == int(v.size()) - 1) {
            std::cout << answer[v.at(i)] << std::endl;
        } else {
            std::cout << answer[v.at(i)] << " ";
        }
    }
}

int main() {
    int size;

    std::cin >> size;

    std::vector<int> v(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> v.at(i);
    }

    indices(v);

    return 0;
}