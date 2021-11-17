#include <iostream>
#include <vector>

void reverse_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (!(begin != end && begin != --end)) {
        return;
    }

    std::iter_swap(begin, end);

    reverse_vector(begin + 1, end);
}

int find_max_element_index(const std::vector<int> &v, int size) {
    if (size < 1) {
        return 0;
    }

    const int max_index = find_max_element_index(v, size - 1);

    if (v.at(max_index) <= v.at(size - 1)) {
        return size - 1;
    }

    return max_index;
}

std::vector<int> tapioca_sort(std::vector<int> &v, std::vector<int> answer = {}, int how_many_sortered = 0) {
    if (how_many_sortered == int(v.size())) {
        answer.push_back(0);

        return answer;
    }

    int greatest_number_index = find_max_element_index(v, v.size() - how_many_sortered);

    if (greatest_number_index + 1 == int(v.size()) - how_many_sortered) {
        ++how_many_sortered;
    } else if (greatest_number_index == 0) {
        reverse_vector(v.begin(), v.end() - how_many_sortered);

        answer.push_back(++how_many_sortered);
    } else {
        reverse_vector(v.begin(), v.begin() + greatest_number_index + 1);

        answer.push_back(v.size() - greatest_number_index);
    }

    return tapioca_sort(v, answer, how_many_sortered);
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