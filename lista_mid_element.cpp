#include <iostream>
#include <utility>
#include <exception>

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

    for (int i {0}; i < n; ++i) {
        ListNode * ptr;
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

int get_middle(ListNode *head) {
    if (head == nullptr) {
        throw std::invalid_argument("Your head must have at least one element");
    }

    ListNode *slow {head};
    ListNode *fast {head};

    while (fast) {
        if (fast->next == nullptr) {
            break;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->value;
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {    
    ListNode *head {read_list()};

    try {
        std::cout << get_middle(head) << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    }

    free(head);
   
    return 0;
}