#include <iostream>
#include <sstream>
#include <limits>
#include "EmailManager.h"
#include "Map.cpp"
#include "Utility.h" // Include Utility.h to use checkCondition

#define GLOBAL_FILE "global.txt"

User* createUser(const std::string& emailAddr);
Email* createEmail(const std::string& sender, const std::string& subject, const std::string& content);
void checkCondition(int &inputNum, int min, int max);

int main() {
    Map<std::string, User> users;
    std::string userArr[1000];
    int userArrInd = 0;
    std::ifstream globalFile(GLOBAL_FILE);
    std::string line;
    EmailManager emailManager;
    int exit = 0;
    int selectUser = 0;

    // Load global email data into users and inboxes
    if (globalFile.is_open()) {
        while (getline(globalFile, line)) {
            std::stringstream ss(line);
            std::string sender, receiver, subject, content;
            getline(ss, sender, ',');
            getline(ss, receiver, ',');
            getline(ss, subject, ',');
            getline(ss, content);

            User tempUser;

            // Insert unique senders and receivers into users map
            if (!users.find(emailManager.parseEmail(sender), tempUser)) {
                users.insert(emailManager.parseEmail(sender), *createUser(sender));
                userArr[userArrInd++] = sender;
            }
            if (!users.find(emailManager.parseEmail(receiver), tempUser)) {
                users.insert(emailManager.parseEmail(receiver), *createUser(receiver));
                userArr[userArrInd++] = receiver;
            }

            // Save the email in the recipient's inbox
            users.find(emailManager.parseEmail(receiver), tempUser);
            emailManager.saveEmail(tempUser, *createEmail(sender, subject, content), FileType::Inbox);
        }
        globalFile.close();
    }

    // Main loop to select user and perform actions
    while (!exit) {
        // User selection
        std::cout << "Select a User: " << std::endl;
        for (int i = 0; i < userArrInd; i++) {
            std::cout << "[" << i << "] " << userArr[i] << std::endl;
        }
        checkCondition(selectUser, 0, userArrInd - 1);

        // Retrieve selected user
        std::string selectedEmail = userArr[selectUser];
        User loginUser;
        users.find(emailManager.parseEmail(selectedEmail), loginUser);

        int logout = 1;
        while (logout) {
            // User-specific menu
            std::cout << "Welcome " << loginUser.getName() << std::endl
                      << "[0] Logout" << std::endl
                      << "[1] Inbox" << std::endl
                      << "[2] Outbox" << std::endl
                      << "[3] Trashcan" << std::endl;
            checkCondition(logout, 0, 3);

            // Menu options
            switch (logout) {
                case 1:
                    std::cout << "\n--- Inbox ---\n";
                    emailManager.viewEmails(loginUser, FileType::Inbox);
                    break;
                case 2:
                    std::cout << "\n--- Outbox ---\n";
                    emailManager.viewEmails(loginUser, FileType::Outbox);
                    break;
                case 3:
                    std::cout << "\n--- Trashcan ---\n";
                    emailManager.viewEmails(loginUser, FileType::Trashcan);
                    break;
                case 0:
                    logout = 0;  // Log out
                    break;
            }
        }
    }
    return 0;
}

User* createUser(const std::string& emailAddr) {
    return new User(emailAddr);
}

Email* createEmail(const std::string& sender, const std::string& subject, const std::string& content) {
    return new Email(sender, subject, content);
}

void checkCondition(int &inputNum, int min, int max) {
    std::cout << "Please enter a number between " << min << " and " << max << ": ";

    while (true) {
        std::cin >> inputNum;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (std::cin.fail() || inputNum < min || inputNum > max) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
        } else {
            break;
        }
    }
}
