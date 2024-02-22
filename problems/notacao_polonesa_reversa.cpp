#include <iostream>
#include <sstream>
#include <stack>

int operation(char op, std::stack<int> &numbers) {
    int n1, n2;

    n1 = numbers.top();

    numbers.pop();

    n2 = numbers.top();

    numbers.pop();

    switch (op) {
    case '+':
        return n1 + n2;
    case '-':
        return n1 - n2;
    case '*':
        return n1 * n2;
    case '/':
        return n1 / n2;
    default:
        return -1;
    }
}

int solver(std::stringstream& ss) {
    std::stack<int> numbers;
    std::string item;

    while (ss >> item) {
        if (item != "+" && item != "-" && item != "*" && item != "/") {
            std::stringstream aux(item);
            
            int number;

            aux >> number;

            numbers.push(number);
        } else {
            numbers.push(operation(item[0], numbers));
        }
    }

    return numbers.top();
}

int main() {
    std::string line;

    std::getline(std::cin, line);

    std::stringstream ss(line);

    std::cout << solver(ss) << std::endl;

    return 0;
}