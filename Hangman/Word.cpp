#include "pch.h"

#include "Word.h"
#include <cctype>
#include <iostream>

Word::Word(const std::string& word) : secret(word), revealed(word.size(), false) {}

bool Word::Guess(char letter) {
    bool found = false;
    letter = std::tolower(letter);

    for (size_t i = 0; i < secret.size(); ++i) {
        if (std::tolower(secret[i]) == letter) {
            revealed[i] = true;
            found = true;
        }
    }

    return found;
}

void Word::Display() {
    for (size_t i = 0; i < secret.size(); ++i) {
        if (revealed[i]) {
            std::cout << secret[i];
        }
        else {
            std::cout << "_";
        }
        std::cout << " ";
    }
    std::cout << std::endl << std::endl;
}

bool Word::IsFullyRevealed() {
    for (bool r : revealed) {
        if (!r) return false;
    }
    return true;
}