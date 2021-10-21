#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> criarNovoVetor(std::vector<int>::iterator begin, std::vector<int>::iterator end, std::vector<int> v = {}) {
    if (begin == end - 1) {
        return v;
    }

    v.push_back(*begin + *(begin + 1));

    return criarNovoVetor(begin + 1, end, v);
}

std::vector<std::vector<int>> trianguloDaSoma(std::vector<int> v, std::vector<std::vector<int>> matriz = {}) {
    matriz.insert(matriz.begin(), v);

    if (v.size() == 1) {
        return matriz;
    }

    return trianguloDaSoma(criarNovoVetor(v.begin(), v.end()), matriz);
}

int main() {
    std::vector<int> v;
    std::stringstream ss;
    std::string line;

    std::getline(std::cin, line);

    ss << line;

    int value;

    while(ss >> value) {
        v.push_back(value);
    }

    std::vector<std::vector<int>> matriz = trianguloDaSoma(v);

    for (std::vector<int> &v : matriz) {
        std::cout << "[ ";

        for (int &value : v) {
            std::cout << value << " ";
        }

        std::cout << "]\n";
    }

    return 0;
}