#include <iostream>
#include <vector>
#include <stack>

std::vector<int> solver(const std::vector<int> &v) {
    int size {int(v.size())};
    std::vector<int> answers(size, -1);
    std::stack<int> s;

    s.push(0);

    for (int i {1}; i < size; ++i) {
        if (v.at(s.top()) < v.at(i)) {
            while (!s.empty() && v.at(s.top()) < v.at(i)) {
                answers.at(s.top()) = i;
                
                s.pop();
            }
        }

        s.push(i);
    }

    return answers;
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> numbers(n);
    std::stack<int> s;

    for (int i {0}; i < n; ++i) {
        std::cin >> numbers.at(i);
    }

    std::vector<int> answers {solver(numbers)};

    int count {0};

    for (int answer : answers) {
        if (count++ > 0) {
            std::cout << " ";
        }

        std::cout << answer;
    }

    std::cout << std::endl;

    return 0;
}