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

    Node* find(int data) {
        return this->find(this->root, data);
    }

    int get_altura(Node *node) {
        if (node == nullptr) {
            return 0;
        }

        return 1 + std::max(this->get_altura(node->left), this->get_altura(node->right));
    }

    int get_profundidade(Node *node) {
        return this->get_profundidade(this->root, node);
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

    Node* find(Node *node, int data) {
        if (node == nullptr) {
            return nullptr;
        }

        if (node->data == data) {
            return node;
        }

        Node *left {this->find(node->left, data)};
        Node *right {this->find(node->right, data)};

        return left != nullptr ? left : right;
    }

    int get_profundidade(Node *current_node, Node *destiny) {
        if (current_node == nullptr) {
            return -1;
        }

        if (current_node == destiny) {
            return 1;
        }

        int left {this->get_profundidade(current_node->left, destiny)};
        int right {this->get_profundidade(current_node->right, destiny)};

        return left != -1 ? left + 1 : right != -1 ? right + 1 : -1;
    }
};

int main() {
    std::string line;

    std::getline(std::cin, line);

    BTree bt(line);

    std::getline(std::cin, line);

    std::stringstream ss(line);

    int value;

    while(ss >> value) {
        Node *node {bt.find(value)};

        if(node != nullptr) {
            std::cout << bt.get_altura(node) << " " << bt.get_profundidade(node) << "\n";
        } else {
            std::cout << "-1\n";
        }
    }

    return 0;
}