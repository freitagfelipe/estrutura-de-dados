#include <iostream>
#include <sstream>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data = 0, Node *left = nullptr, Node *right = nullptr) {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class BTree {
public:
    BTree() {
        this->root = nullptr;
    }


    BTree(const std::string &serial) {
        this->root = nullptr;
        
        std::istringstream ss(serial);

        this->construct(this->root, ss);
    }

    ~BTree() {
        this->destroy(this->root);
    }

    std::string find_path(int data) {
        return this->find_path(this->root, data);
    }

private:
    Node *root;

    void construct(Node *&node, std::istringstream &iss) {
        std::string aux;

        if (!(iss >> aux) || aux == "#") {
            return;
        }

        node = new Node(std::stoi(aux));
        
        this->construct(node->left, iss);
        this->construct(node->right, iss);
    }

    void destroy(Node *node) {
        if(node == nullptr) {
            return;
        }

        this->destroy(node->left);
        this->destroy(node->right);

        delete node;
    }

    std::string find_path(Node *node, int data) {
        if (node == nullptr) {
            return "!";
        } else if (node->data == data) {
            return "x";
        }

        std::string left {this->find_path(node->left, data)};
        std::string right {this->find_path(node->right, data)};

        return left != "!" ? "l" + left : right != "!" ? "r" + right : "!";
    }
};

int main() {
    std::string line;

    std::getline(std::cin, line);

    BTree bt(line);

    int data;

    std::cin >> data;

    std::string path {bt.find_path(data)};

    std::cout << path << "\n";

    return 0;
}