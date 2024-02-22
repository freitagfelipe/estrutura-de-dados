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

    int sum() {
        return this->sum(this->root);
    }

    int min() {
        if (this->root == nullptr) {
            throw std::runtime_error("Error: your tree is empty!");
        }

        return this->min(this->root);
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

    int sum(Node *node) {
        if (node == nullptr) {
            return 0;
        }

        return node->data + this->sum(node->left) + this->sum(node->right);
    }

    int min(Node *node) {
        if (node->left == nullptr && node->right == nullptr) {
            return node->data;
        } else if (node->left == nullptr) {
            return std::min(node->data, this->min(node->right));
        } else if (node->right == nullptr) {
            return std::min(node->data, this->min(node->left));
        }

        return std::min(node->data, std::min(this->min(node->left), this->min(node->right)));
    }
};

int main() {
    std::string line;

    std::getline(std::cin, line);

    BTree bt(line);

    std::cout << bt.sum() << " " << bt.min() << std::endl;

    return 0;
}