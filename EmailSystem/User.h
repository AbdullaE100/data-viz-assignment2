//
// Created by Jasper yong on 8/11/2024.
//

#ifndef EMAILSYSTEM_USER_H
#define EMAILSYSTEM_USER_H

#include <iostream>
#include <string>
#include "Queue.h"
#include "Stack.h"  // Use Stack.h instead of Stack.cpp

using namespace std;

class User {
private:
    string email;
    Stack<Email> inbox;
    Stack<Email> outbox;
    Stack<Email> trashcan;

public:
    User();
    User(const string &email);

    const string &getEmail() const;
    void setEmail(const string &email);
    string getName();

    Stack<Email> &getInbox();
    Stack<Email> &getOutbox();
    Stack<Email> &getTrashcan();
};

#endif // EMAILSYSTEM_USER_H
