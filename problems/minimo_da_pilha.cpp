#include <iostream>
#include <stack>

template <class T>
class StackMin {
public:
    void push(T x) {
        this->data.push(x);
        
        if (this->min.empty() || this->min.top() > x) {
            this->min.push(x);
        }
    }

    bool empty() {
        return this->data.empty();
    }

    T top() {
        return this->data.top();
    }

    void pop() {
        if (this->data.top() <= this->min.top()) {
            this->min.pop();
        }

        this->data.pop();
    }

    T getmin() {
        return this->min.top();
    }

private:
    std::stack<T> data;
    std::stack<T> min;
};

int main() {
    int n;
    StackMin<int> s;

    std::cin >> n;

    for(int i {0}; i < n; ++i) {
        int op, x;

        std::cin >> op;
        
        if(op == 1) {
            std::cin >> x;
            s.push(x);
        } else if(op == 2) {
            s.pop();
        } else{ 
            std::cout <<  s.getmin() << std::endl;
        }
    }

    return 0;
}