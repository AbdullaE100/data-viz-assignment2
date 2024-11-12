// Utility.cpp
#include <iostream>
#include <limits>
#include "Utility.h"  // Include only if checkCondition is declared in Utility.h

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
