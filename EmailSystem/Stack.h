// Stack.h

#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    Stack() = default;   // Constructor
    ~Stack() = default;  // Destructor

    void push(const T& element);
    T pop();
    T peek() const;
    bool isEmpty() const;
    int getSize() const;
    T getEmailAt(int index) const;
};

// Pushes an item onto the stack
template <typename T>
void Stack<T>::push(const T& element) {
    elements.push_back(element);
}

// Removes and returns the top item of the stack
template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    T topElement = elements.back();
    elements.pop_back();
    return topElement;
}

// Returns the top item of the stack without removing it
template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return elements.back();
}

// Checks if the stack is empty
template <typename T>
bool Stack<T>::isEmpty() const {
    return elements.empty();
}

// Returns the size of the stack
template <typename T>
int Stack<T>::getSize() const {
    return elements.size();
}

// Retrieves an item at a specific index (0-based)
template <typename T>
T Stack<T>::getEmailAt(int index) const {
    if (index < 0 || index >= getSize()) {
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}

#endif // STACK_H
