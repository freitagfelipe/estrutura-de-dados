#include <iostream>
#include <vector>
#include <iomanip>

template <typename T> 
class NodeTree {
public:
    T key;
    NodeTree<T> *left;
    NodeTree<T> *right;

    NodeTree(T key) : key(key) {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }

    NodeTree(T key, NodeTree *left, NodeTree *right) : left(left), right(right) {
        this->key = key;
    }
};

template <typename T> 
NodeTree<T>* insert(NodeTree<T> *root, T key) {
    if (root == nullptr) {
        return new NodeTree<T>(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

template <typename T> 
NodeTree<T>* createTree(std::vector<T> keys) {
    NodeTree<T> *root {nullptr};

    for (T key : keys) {
        root = insert(root, key);
    }

    return root;
}

template <typename T> 
bool find(NodeTree<T> *root, int start, int end) {
    if (root == nullptr) {
        return true;
    } else if (root->left == nullptr && root->right == nullptr) {
        return root->key >= start && root->key <= end;
    }

    bool left {find(root->left, start, end)};

    if (left) {
        std::cout << root->left << "\n======" << std::endl;
    }

    bool right {find(root->right, start, end)};

    if (right) {
        std::cout << root->right << "\n======" << std::endl;
    }

    if (left && right) {
        return true;
    }

    return false;
}

template <typename T>
std::ostream& operator<<(std::ostream &os, const NodeTree<T> *ptr) {
    static int offset = 0;

    if(ptr == nullptr) {
        os << " " << std::setw(offset);
        os << "-\n";
    } else {
        offset += 3;

        os << ptr->left;

        offset -= 3;

        os << " " << std::setw(offset);
        os << ptr->key << std::endl;
        
        offset += 3;

        os << ptr->right;

        offset -= 3;
    }   

    return os;
}

int main() {
    int n, start, end;

    std::cin >> n >> start >> end;

    std::vector<int> keys(n);
    
    for(int i {0}; i < n; ++i) {
        std::cin >> keys.at(i);
    }

    NodeTree<int> *root {createTree(keys)};
 
    find(root, start, end);

    return 0;
}