#include <iostream>
#include <vector>

int partition(std::vector<int> &v, int start, int end) {
    int pivot = v.at(end);
    int current_position = start - 1;

    for (int i {start}; i < end; ++i) {
        if (v.at(i) <= pivot) {
            std::swap(v.at(++current_position), v.at(i));
        }
    }

    std::swap(v.at(++current_position), v.at(end));

    return current_position;
}

void quick_sort(std::vector<int> &v, int start, int end) {
    if (start < end) {
        int pivot_position = partition(v, start, end);

        quick_sort(v, start, pivot_position - 1);
        quick_sort(v, pivot_position + 1, end);
    }
}

bool vacas_agressivas(const std::vector<int> &v, int max_distance, int number_of_cows) {
    int current_distance {max_distance};

    --number_of_cows;

    for (int i {0}; i < int(v.size()) - 1; ++i) {
        current_distance -= v.at(i + 1) - v.at(i);

        if (current_distance <= 0) {
            current_distance = max_distance;
            --number_of_cows;
        }

        if (number_of_cows == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    int number_of_slots, number_of_cows;

    std::cin >> number_of_slots >> number_of_cows;

    std::vector<int> distances(number_of_slots, 0);

    for (int i {0}; i < number_of_slots; ++i) {
        std::cin >> distances.at(i);
    }

    quick_sort(distances, 0, distances.size() - 1);

    int start {distances.front()}, end {distances.back()}, answer {0};

    while (start <= end) {
        int mid {(start + end) / 2};

        if (vacas_agressivas(distances, mid, number_of_cows)) {
            answer = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    std::cout << answer << std::endl;

    return 0;
}
