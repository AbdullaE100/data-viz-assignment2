#include <sstream>
#include <limits>
#include <fstream>
#include "EmailManager.h"
#include "Utility.h" // Include Utility.h to use checkCondition

// Constructor
EmailManager::EmailManager() {}

// Detect if an email contains spam keywords
bool EmailManager::isSpam(Email &email) {
    std::string spamKeywords[12] = {
        "win", "free", "urgent", "act now", "limited time", "prize", "congratulations",
        "click here", "guaranteed", "offer", "100%", "act now"
    };
    for (const std::string& keyword : spamKeywords) {
        if (email.getContent().find(keyword) != std::string::npos) {
            return true;
        }
    }
    return false;
}

// Save email to user-specific file based on FileType
void EmailManager::saveEmail(User& user, Email &email, FileType fileType) {
    std::string file;
    Stack<Email>* stack;

    // Determine the correct file and stack based on fileType and spam status
    switch (fileType) {
        case FileType::Inbox:
            if (!isSpam(email)) {
                file = user.getName() + "_inbox.txt";
                stack = &(user.getInbox());
            } else {
                file = user.getName() + "_trashcan.txt";
                stack = &(user.getTrashcan());
            }
            break;
        case FileType::Outbox:
            file = user.getName() + "_outbox.txt";
            stack = &(user.getOutbox());
            break;
        case FileType::Trashcan:
            file = user.getName() + "_trashcan.txt";
            stack = &(user.getTrashcan());
            break;
    }

    // Push email to stack and write to file
    stack->push(email);
    std::ofstream writeFile(file, std::ios::app);
    writeFile << email.getSender() << "," << email.getSubject() << ",\"" << email.getContent() << "\"\n";
    writeFile.close();
}

// Display emails based on FileType, allowing user to view full content
void EmailManager::viewEmails(User &user, FileType fileType) {
    Stack<Email>* stack;
    std::string s = "From";
    int selectedEmail;

    // Select stack based on FileType
    switch (fileType) {
        case FileType::Inbox:
            stack = &(user.getInbox());
            break;
        case FileType::Outbox:
            stack = &(user.getOutbox());
            s = "To";
            break;
        case FileType::Trashcan:
            stack = &(user.getTrashcan());
            break;
    }

    // Check if the stack is empty and notify the user
    if (stack->isEmpty()) {
        std::cout << "\n-- " << (fileType == FileType::Inbox ? "Inbox" : fileType == FileType::Outbox ? "Outbox" : "Trash") << " --\n";
        std::cout << "No emails available.\n";
        return; // Exit the function if no emails are available
    }

    // Display emails
    bool continueViewing = true;
    while (continueViewing) {
        std::cout << "\n-- " << (fileType == FileType::Inbox ? "Inbox" : fileType == FileType::Outbox ? "Outbox" : "Trash") << " --\n";
        for (int i = 0; i < stack->getSize(); ++i) {
            Email email = stack->getEmailAt(i);
            std::cout << "[" << i << "] " << s << ": " << email.getSender()
                      << " | Subject: " << email.getSubject() << "\n";
        }

        std::cout << "Enter the email number to view content (or -1 to exit): ";
        checkCondition(selectedEmail, -1, stack->getSize() - 1);

        if (selectedEmail == -1) {
            continueViewing = false;
        } else {
            Email email = stack->getEmailAt(selectedEmail);
            std::cout << "\nContent:\n" << email.getContent() << "\n";
        }

        // Clear the terminal after each view
        std::string input;
        std::cout << "Press Enter to continue...";
        std::getline(std::cin, input);
        system("clear");
    }
}

// Extracts user identifier from email address (e.g., "john" from "john@example.com")
std::string EmailManager::parseEmail(std::string emailAddr) {
    std::string parsedEmail;
    std::stringstream ss(emailAddr);
    std::getline(ss, parsedEmail, '@');
    return parsedEmail;
}
