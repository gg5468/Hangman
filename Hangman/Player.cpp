#include "Player.h"
#include <iostream>
#include <string>

char const Player::GetUserInput(std::istream& inputStream)
{
    std::string input;

    while (true) {
        std::cout << "Enter a letter: ";
        std::getline(inputStream, input);

        if (input.size() == 1 && std::isalpha(static_cast<unsigned char>(input[0]))) {
            return input[0];
        }
        else {
            std::cout << "Invalid input. Please enter a single letter (a-z).\n";
        }
    }
}

