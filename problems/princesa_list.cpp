#include <iostream>
#include <list>

void output(const std::list<int> &l, const std::list<int>::iterator current_it) {
    std::cout << "[ ";

    int count {0};

    for (std::list<int>::const_iterator it {l.begin()}; it != l.end(); ++it) {
        if (count++ > 0) {
            std::cout << " ";
        }

        std::cout << *it << (it == current_it ? ">" : "");
    }

    std::cout << " ]" << std::endl;
}

int main() {
    int n, start;

    std::cin >> n >> start;

    std::list<int> numbers;
    
    for (int i {1}; i <= n; ++i) {
        numbers.push_back(i);
    }

    std::list<int>::iterator it {numbers.begin()};

    std::advance(it, start - 1);

    while (numbers.size() > 1) {
        output(numbers, it);
        
        if (std::next(it) == numbers.end()) {
            it = numbers.erase(numbers.begin());
        } else {
            it = numbers.erase(++it);

            if (it == numbers.end()) {
                it = numbers.begin();
            }
        }
    }

    output(numbers, it);

    return 0;
}