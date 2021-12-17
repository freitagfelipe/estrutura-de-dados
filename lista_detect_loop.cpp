#include <iostream>
#include <unordered_set>

class ListNode {
public:
    int value;
    ListNode *next;
    
    ListNode() : value(0), next(nullptr) {}
    ListNode(int x) : value(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : value(x), next(next) {} 
};
 
ListNode* read_list() {
    int n, x;

    std::cin >> n >> x;

    ListNode *head {nullptr};
    ListNode *tmp {nullptr};
    ListNode *ptr;
        
    for (int i {1}; i <= n; ++i) {
        int v;

        std::cin >> v;

        if (i == 1) {
            head = new ListNode(v);
            ptr = head;
        } else {
            ptr->next = new ListNode(v, nullptr);
            ptr = ptr->next;
        }

        if (i == x){
            tmp = ptr;
        }
    }
    
    ptr->next = tmp;

    return head;
}

bool detect_loop(ListNode *head) {
    ListNode *slow {head};
    ListNode *fast {head};

    while (fast) {
        if (fast->next == nullptr) {
            break;
        }

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }

    return false;
}

void free(ListNode *head) {
    std::unordered_set<ListNode*> adresses;

    while (head != nullptr && adresses.find(head) == adresses.end()) {
        adresses.insert(head);

        head = head->next;
    }

    for (ListNode* adress : adresses) {
        delete adress;
    }
}

int main() {
    ListNode *head {read_list()};
    
    std::cout << detect_loop(head) << std::endl;

    free(head);

    return 0;    
}