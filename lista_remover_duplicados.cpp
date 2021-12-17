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

void delete_duplicates(ListNode *head) {
    if (head == nullptr) {
        return;
    }

    ListNode *current {head};
    ListNode *ptr {head->next};

    while (ptr != nullptr) {
        if (current->value == ptr->value) {
            delete std::exchange(ptr, ptr->next);
        } else {
            current->next = ptr;
            current = current->next;
            ptr = ptr->next;
        }
    }

    current->next = ptr;
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {
    ListNode *head {nullptr};
    int n;

    std::cin >> n;

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

    delete_duplicates(head);

    for (ListNode *ptr {head}; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << std::endl;
    }

    free(head);
    
    return 0;
}