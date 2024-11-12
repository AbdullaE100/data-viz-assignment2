//
// Created by Jasper yong on 6/11/2024.
//

#ifndef EMAILSYSTEM_EMAILMANAGER_H
#define EMAILSYSTEM_EMAILMANAGER_H

#include <iostream>
#include <fstream>
#include <string>
#include "Email.h"
#include "Queue.h"
#include "User.h"

using namespace std;

enum class FileType {
    Inbox,
    Outbox,
    Trashcan
};

// Declare checkCondition function here
void checkCondition(int &inputNum, int min, int max);

class EmailManager {
private:
    Stack<Email>* stack;
    bool isSpam(Email& email);

public:
    explicit EmailManager();
    void saveEmail(User& user, Email& email, FileType fileType);
    string parseEmail(string emailAddr);
    void viewEmails(User& user, FileType fileType);
};

#endif // EMAILSYSTEM_EMAILMANAGER_H
