// Email.h

#ifndef EMAIL_H
#define EMAIL_H

#include <string>

class Email {
private:
    std::string sender;
    std::string receiver;
    std::string subject;
    std::string content;

public:
    // Constructor with parameters
    Email(const std::string &sender, const std::string &subject, const std::string &content, const std::string &receiver = "");

    // Default constructor
    Email();

    // Getters
    const std::string& getSender() const;
    const std::string& getReceiver() const;
    const std::string& getSubject() const;
    const std::string& getContent() const;

    // Setters
    void setSender(const std::string &s);
    void setReceiver(const std::string &r);
    void setSubject(const std::string &subj);
    void setContent(const std::string &cont);
};

#endif // EMAIL_H
