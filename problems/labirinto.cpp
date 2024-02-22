#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Position {
    int x;
    int y;

    Position() = default;

    Position(int x, int y) {
        this->x = x;
        this->y = y;
    }

    friend bool operator==(const Position &left, const Position &right) {
        return left.x == right.x && left.y == right.y;
    }

    friend bool operator!=(const Position &left, const Position &right) {
        return left.x != right.x || left.y != right.y;
    }
};

std::ostream& operator<<(std::ostream &os, const std::vector<std::string> &v) {
    int count {0};

    for (const std::string &line : v) {
        if (count++ > 0) {
            os << "\n";
        }

        os << line;
    }

    return os;
}

std::vector<Position> get_neighbors(const Position &current) {
    return {{current.x, current.y + 1}, {current.x, current.y - 1}, {current.x + 1, current.y}, {current.x - 1, current.y}};
}

std::pair<Position, Position> get_start_and_end(std::vector<std::string> &maze) {
    Position start, end;

    for (size_t i {0}; i < maze.size(); ++i) {
        for (size_t j {0}; j < maze.at(0).size(); ++j) {
            if (maze.at(i).at(j) == 'I') {
                maze.at(i).at(j) = ' ';

                start = Position(i, j);
            } else if (maze.at(i).at(j) == 'F') {
                maze.at(i).at(j) = ' ';

                end = Position(i, j);
            }
        }
    }

    return {start, end};
}

void make_path(std::vector<std::string> &maze, std::vector<std::vector<int>> &distances, Position start, Position end) {
    Position current {end};

    std::queue<Position> path;

    path.push(end);

    while (current != start) {
        std::vector<Position> neighbors {get_neighbors(current)};
        Position lowest_neighbor {neighbors.at(0)};

        auto &[lx, ly] {lowest_neighbor};

        for (size_t i {1}; i < neighbors.size(); ++i) {
            auto [x, y] {neighbors.at(i)};

            if (distances.at(x).at(y) < distances.at(lx).at(ly)) {
                lowest_neighbor = neighbors.at(i);
            }
        }

        current = lowest_neighbor;

        path.push(lowest_neighbor);
    }

    while (!path.empty()) {
        auto [x, y] {path.front()};

        maze.at(x).at(y) = '.';

        path.pop();
    }
}

void find_path(std::vector<std::string> &maze, Position start, Position end) {
    std::vector<std::vector<int>> distances(maze.size(), std::vector<int>(maze.at(0).size(), INT_MAX));
    std::queue<Position> positions;

    positions.push(start);

    distances.at(start.x).at(start.y) = 0;

    while (!positions.empty()) {
        Position current {positions.front()};

        for (Position &neighbor : get_neighbors(current)) {
            auto &[x, y] {neighbor};

            if (maze.at(x).at(y) != '#' && distances.at(x).at(y) == INT_MAX) {
                distances.at(x).at(y) = distances.at(current.x).at(current.y) + 1;

                positions.push(neighbor);
            }

            if (neighbor == end) {
                make_path(maze, distances, start, end);

                return;
            }
        }

        positions.pop();
    }
}

int main() {
    int lines, columns;

    std::cin >> lines >> columns;

    std::cin.get();

    std::vector<std::string> maze(lines);

    for (int i {0}; i < lines; ++i) {
        std::getline(std::cin, maze.at(i));
    }

    auto &&[start, end] {get_start_and_end(maze)};

    find_path(maze, start, end);
    
    std::cout << maze << std::endl;

    return 0;
}