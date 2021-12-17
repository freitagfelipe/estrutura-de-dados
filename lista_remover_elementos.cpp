#include <iostream>
#include <utility>

class ListNode {
public:
    int value;
    ListNode *next;

    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : value(x), next(next) {} 
};

ListNode* remove_elements(ListNode *head, int value)  {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->value == value) {
        delete std::exchange(head, head->next);

        return remove_elements(head, value);
    }

    head->next = remove_elements(head->next, value);

    return head;
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {
    int n, value;
    ListNode *head {nullptr};

    std::cin >> n >> value;

    for (int i {0}; i < n; ++i) {
        ListNode *ptr;
        int x;

        std::cin >> x;

        if(i == 0) {
            head = new ListNode(x);
            ptr = head;
        } else {
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    head = remove_elements(head, value);

    for (ListNode *ptr {head}; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << std::endl;
    }

    free(head);
    
    return 0;
}