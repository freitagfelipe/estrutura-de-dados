#include <iostream>
#include <vector>
#include <set>

void insert_in_set(std::set<int> &set, int size) {
    for (int i {0}; i < size; ++i) {
        int num;
    
        std::cin >> num;

        set.insert(num);
    }
}

int main() {
    std::set<int> collection_one, collection_two;
    int size;

    std::cin >> size;

    insert_in_set(collection_one, size);
    insert_in_set(collection_two, size);

    for (const int &number : collection_one) {
        if (collection_two.find(number) == collection_two.end()) {
            std::cout << 0 << std::endl;

            return 0;
        }
    }

    std::cout << 1 << std::endl;

    return 0;
}