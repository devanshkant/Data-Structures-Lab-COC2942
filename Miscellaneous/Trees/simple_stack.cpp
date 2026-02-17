#ifndef SIMPLE_STACK_H
#define SIMPLE_STACK_H
#include <stdexcept>

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack() {
        while (!isEmpty())
            pop();
    }

    bool isEmpty() const {
        return topNode == nullptr;
    }

    void push(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = topNode;
        topNode = newNode;
    }

    void pop() {
        if (isEmpty()) return;  // safe pop

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    T top() const {
        if (isEmpty())
            throw std::underflow_error("Stack is empty");

        return topNode->data;
    }
};

#endif
