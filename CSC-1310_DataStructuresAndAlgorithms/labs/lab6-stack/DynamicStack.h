#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

template <typename T>
class DynamicStack
{
private:
    struct ListNode
    {
        T value;
        ListNode *next;
    };

    ListNode *top;

public:
    LinkedList()
    {
        top = NULL;
    }
    bool isEmpty() const;
    void push(T value);
    void pop(T item);
};

template <typename T>
bool DynamicStack<T>::isEmpty() const
{
    return (!top);
}

template <typename T>
void DynamicStack<T>::push(T value)
{
    ListNode *newNode = new ListNode;
    newNode->value = value;

    // Makes the new value point next to what is currently on top (NULL if thte stack is empty)
    isEmpty() ? newNode->next = NULL : newNode->next = top;

    // Then redefines the top to the new value that was placed on top
    top = newNode;
}

template <typename T>
void DynamicStack<T>::pop(T item)
{
    if (isEmpty())
    {
        return;
    }

    ListNode deletedNode = top;
    top = top->next;
    item = deletedNode->value;
    delete deletedNode;
}

#endif