#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

template <typename T>
class DynamicStack {
private:
    struct ListNode {
        T value;
        ListNode *next;
    };

    ListNode *top;

public:
    DynamicStack() {
        top = NULL;
    }
    bool isEmpty() const;
    void push(T value);
    void pop(T &item);
};

template <typename T>
bool DynamicStack<T>::isEmpty() const {
    return (!top);
}

template <typename T>
void DynamicStack<T>::push(T value) {
    ListNode *newNode = new ListNode;
    newNode->value = value;

    // Makes the new value point next to what is currently on top
    {
        // isEmpty() ? newNode->next = NULL : newNode->next = top;
        // The above check is not needed, as the newNode would be set to NULL even if the stack is empty because top would be NULL
        newNode->next = top;
    }

    // Then redefines the top to the new value that was placed on top
    top = newNode;
}

template <typename T>
void DynamicStack<T>::pop(T &item) {
    if (isEmpty()) {
        return;
    }

    ListNode *deleteNode = top;
    top = top->next;
    item = deleteNode->value;
    delete deleteNode;
}

#endif