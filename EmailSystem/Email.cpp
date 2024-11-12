// Email.cpp

#include "Email.h"

// Parameterized constructor
Email::Email(const std::string &sender, const std::string &subject, const std::string &content, const std::string &receiver)
    : sender(sender), receiver(receiver), subject(subject), content(content) {}

// Default constructor
Email::Email() = default;

// Getters
const std::string& Email::getSender() const { return sender; }
const std::string& Email::getReceiver() const { return receiver; }
const std::string& Email::getSubject() const { return subject; }
const std::string& Email::getContent() const { return content; }

// Setters
void Email::setSender(const std::string &s) { sender = s; }
void Email::setReceiver(const std::string &r) { receiver = r; }
void Email::setSubject(const std::string &subj) { subject = subj; }
void Email::setContent(const std::string &cont) { content = cont; }
