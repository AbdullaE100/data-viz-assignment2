#include "User.h"

// Constructor initializing email
User::User(const std::string &email) : email(email) {}

// Default constructor, setting email to empty string
User::User() : email("") {}

// Get email address
const std::string &User::getEmail() const {
    return email;
}

// Set email address
void User::setEmail(const std::string &email) {
    User::email = email;
}

// Extract and return username from email (everything before '@')
std::string User::getName() {
    size_t pos = email.find("@");
    return email.substr(0, pos);
}

// Access inbox stack
Stack<Email>& User::getInbox() {
    return inbox;
}

// Access outbox stack
Stack<Email>& User::getOutbox() {
    return outbox;
}

// Access trashcan stack
Stack<Email>& User::getTrashcan() {
    return trashcan;
}
