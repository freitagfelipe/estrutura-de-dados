#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

std::string vet(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::stringstream ss;

    ss << *begin;

    if (begin + 1 == end) {
        return ss.str();
    }

    ss << " ";

    return ss.str().append(vet(++begin, end));
}

std::string rvet(std::vector<int>::reverse_iterator rbegin, std::vector<int>::reverse_iterator rend) {
    std::stringstream ss;

    ss << *rbegin;

    if (rbegin + 1 == rend) {
        return ss.str();
    }

    ss << " ";

    return ss.str().append(rvet(++rbegin, rend));
}

int sum(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end) {
        return 0;
    }

    return *begin + sum(++begin, end);
}

int mult(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin == end) {
        return 1;
    }

    return *begin * mult(++begin, end);
}

int minimo(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin + 1 == end) {
        return *begin;
    }

    return std::min(*begin, minimo(begin + 1, end));
}

std::string inv(std::vector<int> &v, std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (!(begin != end && begin != --end)) {
        return vet(v.begin(), v.end());
    }

    std::iter_swap(begin, end);

    return inv(v, ++begin, end);
}

int main() {
    std::string line;
    std::vector<int> v;

    std::getline(std::cin, line);

    std::stringstream ss(line);

    int value;

    while(ss >> value) {
        v.push_back(value);
    }

    std::cout << "vet : [ " << vet(v.begin(), v.end()) << " ]" << std::endl;
    std::cout << "rvet: [ " << rvet(v.rbegin(), v.rend()) << " ]" << std::endl;
    std::cout << "sum : " << sum(v.begin(), v.end()) << std::endl;
    std::cout << "mult: " << mult(v.begin(), v.end()) << std::endl;
    std::cout << "min : " << minimo(v.begin(), v.end()) << std::endl;
    std::cout << "inv : [ " << inv(v, v.begin(), v.end()) << " ]" << std::endl;

    return 0;
}