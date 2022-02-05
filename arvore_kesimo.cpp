#include <iostream>

template <typename T> 
struct NodeTree {
public:
    T data;
    NodeTree<T> *left;
    NodeTree<T> *right;

    NodeTree(T data) : data(data) {
        this->left = nullptr;
        this->right = nullptr;
        
    }

    NodeTree(T data, NodeTree *left, NodeTree *right) : data(data) {
        this->left = left;
        this->right = right;
    }
};

template <typename T> 
void create_tree(NodeTree<T> *&root, int number) {
    if (root == nullptr) {
        root = new NodeTree<T>(number);
    }

    if (number < root->data) {
        create_tree(root->left, number);
    } else if (number > root->data) {
        create_tree(root->right, number);
    }
}

template <typename T> 
NodeTree<T>* kesimo(NodeTree<T> *root, int &k) {
    if (root == nullptr) {
        return nullptr;
    }

    NodeTree<T> *left {kesimo(root->left, k)};

    if (--k == 0) {
        return root;
    }

    return left != nullptr ? left : kesimo(root->right, k);
}

int main() {
    NodeTree<int> *tree {nullptr};
    int n, k;

    std::cin >> n >> k;

    for (int i {0}; i < n; ++i) {
        int number;

        std::cin >> number;

        create_tree(tree, number);
    }

    std::cout << kesimo(tree, k)->data << std::endl;

    return 0;
}