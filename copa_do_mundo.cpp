#include <iostream>
#include <queue>

char solver(std::queue<int> &q) {
    for (int i {0}; i < 15; ++i) {
        int MM, NN;

        std::cin >> MM >> NN;

        if (MM > NN) {
            q.push(q.front());
            q.pop();
            q.pop();
        } else {
            q.pop();
            q.push(q.front());
            q.pop();
        }
    }

    return char('A' + q.front());
}

int main() {
    std::queue<int> q;

    for (int i {0}; i < 16; ++i) {
        q.push(i);
    }

    std::cout << solver(q) << std::endl;

    return 0;
}