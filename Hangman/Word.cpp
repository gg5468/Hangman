#include "Word.h"
#include <cctype>
#include <iostream>
#include <algorithm>


Word::Word(const std::string& word) : secret(word), revealed(word.size()) {
    std::transform(secret.begin(), secret.end(), secret.begin(),
        [](auto c) { return std::tolower(c); });
}

bool const Word::Guess(char letter) {
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

void const Word::Display() {
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

bool const Word::IsFullyRevealed() {
    return std::all_of(revealed.begin(), revealed.end(), [](bool r) { return r; });
}