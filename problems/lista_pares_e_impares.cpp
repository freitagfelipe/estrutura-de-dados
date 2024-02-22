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

ListNode* odd_even_list(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }

    ListNode *odd {head};
    ListNode *even {head->next};
    ListNode *even_start_aux {even};

    while (even && even->next) {
        odd->next = odd->next->next;
        even->next = odd->next->next;

        even = even->next;
        odd = odd->next;
    }

    odd->next = even_start_aux;

    return head;
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {
    int n;
    ListNode *head {nullptr};

    std::cin >> n;

    for(int i {0}; i < n; ++i){
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

    head = odd_even_list(head);

    for(ListNode *ptr {head}; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << std::endl;
    }

    free(head);
    
    return 0;
}