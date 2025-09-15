#include "Word.h"
#include <cctype>
#include <iostream>
#include <algorithm>

Word::Word(const std::string& word) {
    secret = word;
    std::transform(secret.begin(), secret.end(), secret.begin(),
        [](unsigned char c) { return std::tolower(c); });

    revealed = std::vector<bool>(secret.size(), false);
}

bool Word::Guess(char letter) {
    bool found = false;
    letter = std::tolower(letter);

    size_t i = 0;
    for (char ch : secret) {
        if (ch == letter) {
            revealed[i] = true;
            found = true;
        }
        ++i;
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
    return std::all_of(revealed.begin(), revealed.end(), [](bool r) { return r; });
}