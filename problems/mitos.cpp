#include <iostream>
#include <algorithm>
#include <vector>

class Raios {
public:
    Raios(int width, int length) { 
        this->width = width;
        this->length = length;
    }

    void add(int x, int y) {
        this->places.push_back(std::make_pair(x, y));
    }

    bool mesmo_lugar() {
        std::sort(this->places.begin(), this->places.end());

        for (int i {0}; i < int(this->places.size()) - 1; ++i) {
            if (this->places.at(i) == this->places.at(i + 1)) {
                return 1;
            }
        }

        return 0;
    }

private:
    int width;
    int length;
    std::vector<std::pair<int, int>> places;
};

int main() {
    int n;

    std::cin >> n;

    Raios R(500, 500);

    for(int i = 0; i < n; ++i){
        int x, y;

        std::cin >> x >> y;

        R.add(x, y);
    }

    std::cout << R.mesmo_lugar() << std::endl;

    return 0;
}