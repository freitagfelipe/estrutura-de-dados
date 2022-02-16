#include <iostream>

void insert_letter(std::string &answer, char ch, size_t &cursor_position) {
    ++cursor_position;

    if (ch == 'R') {
        ch = '\n';
    }

    answer.insert(cursor_position - 1, 1, ch);
}

void delete_letter(std::string &answer, char ch, size_t &cursor_position) {
    if (ch == 'B') {
        if (cursor_position > 0) {
            answer.erase(--cursor_position, 1);
        }
    } else if (ch == 'D') {
        if (cursor_position < answer.size()) {
            answer.erase(cursor_position, 1);
        }
    }
}

void move_cursor(const std::string &answer, char ch, size_t &cursor_position) {
    if (ch == '<') {
        if (cursor_position > 0) {
            --cursor_position;
        }
    } else if (ch == '>') {
        if (cursor_position < answer.size()) {
            ++cursor_position;
        }
    }
}

int main() {
    std::string line;

    std::getline(std::cin, line);

    size_t cursor_position {0};

    std::string answer;

    for (size_t i {0}; i < line.size(); ++i) {
        char &ch {line.at(i)};

        if ((ch >= 'a' && ch <= 'z') || ch == '-' || ch == 'R') {
            insert_letter(answer, ch, cursor_position);
        } else if (ch == '<' || ch == '>') {
            move_cursor(answer, ch, cursor_position);
        } else if (ch == 'B' || ch == 'D') {
            delete_letter(answer, ch, cursor_position);
        }
    }

    answer.insert(cursor_position, "|");

    std::cout << answer << std::endl;
}