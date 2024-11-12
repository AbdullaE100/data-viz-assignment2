//
// Created by Jasper yong on 8/11/2024.
//

#ifndef EMAILSYSTEM_QUEUE_H
#define EMAILSYSTEM_QUEUE_H
#include <iostream>
#include "Email.h"
using namespace std;

// Node structure
struct Node {
    Email* data;
    Node* next;
    Node(Email* val) : data(val), next(nullptr) {}
};


class Queue {
private:
    Node* front;  // Pointer to the front of the queue
    Node* rear;   // Pointer to the rear of the queue
    int length;
public:
    Queue();
    ~Queue();
    void append(Email email);
    Email* serve();
    Email* peek();
    bool isEmpty()const;

};


#endif //EMAILSYSTEM_QUEUE_H
