#include <iostream>
#include <algorithm>
#include <vector>

int find_max_element_index(const std::vector<int> &v, int end) {
    int greatest {v.at(0)}, index {0};

    for (int i {1}; i < end; ++i) {
        if (greatest < v.at(i)) {
            greatest = v.at(i);
            index = i;
        }
    }

    return index;
}

std::vector<int> tapioca_sort(std::vector<int> &v) {
    std::vector<int> answer;
    int how_many_sortered {0};

    while (how_many_sortered != int(v.size())) {
        int greatest_number_index = find_max_element_index(v, v.size() - how_many_sortered);

        if (greatest_number_index + 1 == int(v.size()) - how_many_sortered) {
            ++how_many_sortered;
        } else if (greatest_number_index == 0) {
            std::reverse(v.begin(), v.end() - how_many_sortered);

            answer.push_back(++how_many_sortered);
        } else {
            std::reverse(v.begin(), v.begin() + greatest_number_index + 1);

            answer.push_back(v.size() - greatest_number_index);
        }
    }

    answer.push_back(0);

    return answer;
}

int main() {
    int size;

    std::cin >> size;

    std::vector<int> v(size, 0);

    for (int i {0}; i < size; ++i) {
        std::cin >> v.at(i);
    }

    int count {0};

    for (const int &number : tapioca_sort(v)) {
        if (count++ > 0) {
            std::cout << " ";
        }

        std::cout << number;
    }

    std::cout << std::endl;

    return 0;
}