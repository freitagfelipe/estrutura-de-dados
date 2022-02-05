#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

class Studant {
public:
    Studant(const std::string &name, int ability) : name(name) {
        this->ability = ability;
    }

    std::string get_name() const {
        return this->name;
    }

    friend bool operator<(const Studant &studant_one, const Studant &studant_two) {
        return studant_one.ability > studant_two.ability;
    }

private:
    std::string name;
    int ability;
};

std::set<std::string> solver(std::vector<Studant> &studants, int n) {
    std::set<std::string> answer;

    int count {n};

    for (std::vector<Studant>::iterator it {studants.begin()}; it != studants.end();) {
        if (count++ == n) {
            answer.insert(it->get_name());

            it = studants.erase(it);

            count = 1;
        } else {
            ++it;
        }
    }

    return answer;
}

std::ostream& operator<<(std::ostream &os, const std::set<std::string> &set) {
    int count {0};

    for (const std::string &string : set) {
        if (count++ > 0) {
            os << "\n";
        }

        os << string;
    }

    return os;
}

int main() { 
    int how_many_studants, how_many_teams;
    
    std::cin >> how_many_studants >> how_many_teams;

    std::vector<Studant> studants;

    for (int i {0}; i < how_many_studants; ++i) {
        std::string name;
        int ability;

        std::cin >> name >> ability;

        studants.emplace_back(name, ability);
    }
    
    std::sort(studants.begin(), studants.end());

    std::cout << "Time 1\n" << solver(studants, 3) << std::endl;
    std::cout << "\nTime 2\n" << solver(studants, 2) << std::endl;
    std::cout << "\nTime 3\n" << solver(studants, 1) << std::endl;

    return 0;
}