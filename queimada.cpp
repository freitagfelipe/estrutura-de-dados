#include <iostream>
#include <vector>

void show(const std::vector<std::string> &matriz) {
    for (std::string line : matriz) {
        std::cout << line << std::endl;
    }
}

void tocarFogo(std::vector<std::string> &matriz, int lfire, int cfire) {
    int nl = matriz.size();
    int nc = matriz.at(0).size();

    if (matriz.at(lfire).at(cfire) == '#') {
        matriz.at(lfire).at(cfire) = 'o';

        if (lfire + 1 < nl) {
            tocarFogo(matriz, lfire + 1, cfire);
        }

        if (lfire - 1 >= 0) {
            tocarFogo(matriz, lfire - 1, cfire);
        }

        if (cfire + 1 < nc) {
            tocarFogo(matriz, lfire, cfire + 1);
        }

        if (cfire - 1 >= 0) {
            tocarFogo(matriz, lfire, cfire - 1);
        }
    }
}

int main() {
    int nl, nc, lfire, cfire;

    std::cin >> nl >> nc >> lfire >> cfire;

    std::vector<std::string> matriz;

    for (int i = 0; i < nl; i++) {
        std::string line;

        std::cin >> line;

        matriz.push_back(line);
    }

    tocarFogo(matriz, lfire, cfire);
    show(matriz);

    return 0;
}