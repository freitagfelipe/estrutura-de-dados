#include <iostream>
#include <list>

void rotation(std::list<int> &list, int number_of_rotations) {
    for (int i {0}; i < number_of_rotations; ++i) {
        list.push_front(list.back());
        list.pop_back();
    }
}

int main() {
    int size, number_of_rotations;
    
    std::cin >> size >> number_of_rotations;

    std::list<int> my_list;

    for (int i {0}; i < size; ++i) {
        int num;

        std::cin >> num;

        my_list.push_back(num);
    }

    rotation(my_list, number_of_rotations);

    std::cout << "[ ";

    for (const int &number : my_list) {
        std::cout << number << " ";
    }

    std::cout << "]" << std::endl;

    return 0;
}