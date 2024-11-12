

#include "Queue.h"

Queue::Queue(): front(nullptr), rear(nullptr) {

}

Queue::~Queue() {
    while (!isEmpty()) {
        serve();
    }
}

void Queue::append(Email email) {
    Node* newNode = new Node(&email);
    if (rear == nullptr) {
        // If queue is empty, new node is both front and rear
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

Email *Queue::serve() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue." << endl;
        return nullptr;
    }
    Node* temp = front;
    front = front->next;

    if (front == nullptr) // If queue is empty after dequeue
        rear = nullptr;
    return temp->data;
}

Email *Queue::peek() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot peek." << endl;
        return nullptr;
    }
    return front->data;
}

bool Queue::isEmpty() const {
    return front == nullptr;;
}
