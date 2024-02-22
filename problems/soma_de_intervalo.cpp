#include <iostream>
#include <vector>

template <typename T> 
class NodeTree {
public:
    T key;
    NodeTree<T> *left;
    NodeTree<T> *right;

    NodeTree(T key) : left(nullptr), right(nullptr) {
        this->left = nullptr;
        this->right = nullptr;
        this->key = key;
    }

    NodeTree(T key, NodeTree *left, NodeTree * right) : left(left), right(right) {
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
NodeTree<T>* create_tree(std::vector<T> keys) {
    NodeTree<T> *root {nullptr};

    for (T key : keys) {
        root = insert(root, key);
    }

    return root;
}

template <typename T> 
T sum(NodeTree<T> *root, int start, int end) {
    if (root == nullptr) {
        return 0;
    }

    int answer {0};

    if (root->key >= start && root->key <= end) {
        answer += root->key;
    }

    answer += sum(root->left, start, end);
    answer += sum(root->right, start, end);

    return answer;
}

int main() {
    int n, start, end;

    std::cin >> n >> start >> end;

    std::vector<int> keys(n);
    
    for (int i {0}; i < n; ++i) {
        std::cin >> keys.at(i);
    }

    NodeTree<int> *root {create_tree(keys)};

    int answer {sum(root, start, end)};

    std::cout << answer << std::endl;

    return 0;
}