#include <iostream>
#include <vector>

class Disjuntos {
public:
    Disjuntos(int n) { 
        for (int i {0}; i < n; ++i) {
            this->numbers.push_back(i);
        }
    }

    void une(int x, int y) {
        this->numbers.at(y) = this->numbers.at(x);
    }

    bool mesmo(int x, int y) {
        if (this->numbers.at(x) == this->numbers.at(y)) {
            return true;
        }

        return false;
    }

private:
    int n;
    std::vector<int> numbers;
};

int main() {

    return 0;
}