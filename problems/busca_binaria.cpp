#include <iostream>
#include <vector>

std::vector<int> busca_binaria(const std::vector<int> &v, const std::vector<int> &queries) {
    std::vector<int> answer;

    for (const int &number : queries) {
        int start {0}, end {int(v.size()) - 1}, count {0};

        while (start <= end) {
            int mid {(start + end) / 2};

            ++count;

            if (v.at(mid) == number) {
                break;
            } else if (v.at(mid) > number) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        answer.push_back(count);
    }

    return answer;
}

int main() {
    int vector_size, queries_size;

    std::cin >> vector_size >> queries_size;

    std::vector<int> numbers(vector_size, 0), queries(queries_size, 0);

    for (int i {0}; i < vector_size; ++i) {
        std::cin >> numbers.at(i);
    }

    for (int i {0}; i < queries_size; ++i) {
        std::cin >> queries.at(i);
    }

    int count {0};

    for (const int &number : busca_binaria(numbers, queries)) {
        if (count++ > 0) {
            std::cout << " ";
        }

        std::cout << number;
    }

    std::cout << std::endl;

    return 0;
}