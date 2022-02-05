#include <iostream>
#include <vector>
#include <climits>

template <typename T> 
struct NodeTree {
    T data;
    size_t size;
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
NodeTree<T>* create_tree(std::vector<T> data, std::vector<int> parents) {
    std::vector<NodeTree<T>*> tree(data.size());

    for (size_t i {0}; i < data.size(); ++i) {
        tree.at(i) = new NodeTree<T>(data.at(i));
    }

    NodeTree<T> *root;

    for(size_t i {0}; i < data.size(); ++i) {
        if (parents.at(i) == -1) {
            root = tree.at(i);
        } else {
            NodeTree<T> *ptr {tree.at(parents.at(i))};

            if (ptr->left) {
                ptr->right = tree.at(i);
            } else {
                ptr->left = tree.at(i);
            }
        }
    }

    return root;
} 

template <typename T>
bool is_BST_aux(NodeTree<T> *root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < min || root->data > max) {
        return false;
    }

    return is_BST_aux(root->left, INT_MIN, root->data) && is_BST_aux(root->right, root->data, INT_MAX);
}

template <typename T>
bool is_BST(NodeTree<T> *root) {
    return is_BST_aux(root, INT_MIN, INT_MAX);
}

int main() {
    int n;

    std::cin >> n;

    std::vector<int> data(n);
    std::vector<int> parents(n);

    for (int i {0}; i < n; ++i) {
        std::cin >> data.at(i);
    }

    for (int i {0}; i < n; ++i) {
        std::cin >> parents.at(i);
    }
    
    NodeTree<int> *root {create_tree(data, parents)};

    std::string answer {is_BST(root) ? "Yes" : "No"}; 

    std::cout << answer << std::endl;

    return 0;
}