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

    void show_in_order() {
        std::cout << "[ ";

        this->show_in_order(this->root);

        std::cout << "]" << std::endl;
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

    void show_in_order(Node *node) {
        if(node == nullptr) {
            return;
        }
            
        this->show_in_order(node->left);

        std::cout << node->data << " ";
        
        this->show_in_order(node->right);
    }
};

int main() {
    std::string line;

    std::getline(std::cin, line);

    BTree bt(line);

    bt.show_in_order();

    return 0;
}