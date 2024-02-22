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

    void show() {
        this->show(this->root);
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

    void show(Node *node, std::string &&spacing = "") {
        if (node == nullptr) {
            std::cout << spacing << "#" << std::endl;

            return;
        } else if (node->left == nullptr && node->right == nullptr) {
            std::cout << spacing << node->data << std::endl;

            return;
        }

        this->show(node->left, spacing + "....");
        
        std::cout << spacing << node->data << std::endl;

        this->show(node->right, spacing + "....");
    }
};

int main() {
    std::string line;

    std::getline(std::cin, line);

    BTree bt(line);

    bt.show();

    return 0;
}