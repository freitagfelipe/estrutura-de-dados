#include <iostream>
#include <tuple>

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

std::tuple<ListNode*, ListNode*> move(ListNode *head_one, ListNode *head_two) {
    if (head_one->value == head_two->value) {
        head_one = head_one->next;
        head_two = head_two->next;
    } else if (head_one->value < head_two->value) {
        head_one = head_one->next;
    } else {
        head_two = head_two->next;
    }

    return std::make_tuple(head_one, head_two);;
}

ListNode* intersection_list(ListNode *head_one, ListNode *head_two) {
    ListNode *result {nullptr};
    ListNode *aux {nullptr};

    while (head_one && head_two) {
        if (head_one->value == head_two->value) {
            if (result == nullptr) {
                result = new ListNode(head_one->value);
                aux = result;
            } else {
                aux->next = new ListNode(head_one->value);
                aux = aux->next;
            }
        }

        std::tie(head_one, head_two) = move(head_one, head_two);
    }

    return result;
}

void print_list(ListNode *head) {
    for (ListNode *ptr {head}; ptr != nullptr; ptr = ptr->next) {
        std::cout << ptr->value << std::endl;
    }
}

void free(ListNode *head) {
    while (head != nullptr) {
        delete std::exchange(head, head->next);
    }
}

int main() {
    ListNode *head_one {read_list()};
    ListNode *head_two {read_list()};
    ListNode *answer {intersection_list(head_one, head_two)};

    print_list(answer);

    free(head_one);
    free(head_two);
    free(answer);

    return 0;
}