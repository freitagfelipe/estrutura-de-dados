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
 
ListNode* read_list() {
    int n;

    std::cin >> n;

    ListNode *head {nullptr};

    for (int i = 0; i < n; ++i) {
        ListNode *ptr;
        int x;

        std::cin >> x;

        if (i == 0) {
            head = new ListNode(x);
            ptr = head;
        } else {
            ptr->next = new ListNode(x, nullptr);
            ptr = ptr->next;
        }
    }

    return head;
}

void print_list(ListNode *head) {
    for (ListNode *ptr {head}; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << std::endl;
    }
}

ListNode* soma_um(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    if (head->next == nullptr) {
        ++head->value;
    }

    head->next = soma_um(head->next);

    if (head->next != nullptr && head->next->value == 10) {
        ++head->value;
        head->next->value = 0;
    }

    return head;
}

ListNode* solver(ListNode *head) {
    head = soma_um(head);

    if (head->value == 10) {
        head = new ListNode(1, head);
        head->next->value = 0;
    }

    return head;
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {
    ListNode *head {read_list()};

    head = solver(head);

    print_list(head);

    free(head);

    return 0;
}