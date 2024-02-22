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

ListNode* merge_two_lists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    }

    if (l1->value > l2->value) {
        l2->next = merge_two_lists(l1, l2->next);

        return l2;
    } else {
        l1->next = merge_two_lists(l1->next, l2);

        return l1;
    }
}

ListNode* readList() {
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

    return head;
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {
    ListNode *list1 {readList()};
    ListNode *list2 {readList()};
    ListNode *head {merge_two_lists(list1, list2)};

    for (ListNode *ptr {head}; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << std::endl;
    }

    free(head);
    
    return 0;    
}