#include <iostream>
#include <vector>

int solver(const std::vector<std::string> &words, const std::string &string_to_check) {
    int count {0};

    for (const std::string &word : words) {
        if (word == string_to_check) {
            ++count;
        }
    }

    return count;
}

int main() {
    std::vector<int> answer;
    int size;

    std::cin >> size;

    std::vector<std::string> palavras(size, "");

    for (int i {0}; i < size; ++i) {
        std::cin >> palavras.at(i);
    }

    std::cin >> size;

    std::vector<std::string> consultas(size, "");

    for (int i {0}; i < size; ++i) {
        std::cin >> consultas.at(i);
    }

    for (const std::string &consulta : consultas) {
        answer.push_back(solver(palavras, consulta));
    }

    int count {0};

    for (const int &number : answer) {
        if (count++ > 0) {
            std::cout << " ";
        }
        
        std::cout << number;
    }

    std::cout << std::endl;

    return 0;
}