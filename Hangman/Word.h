#pragma once
#include <string>
#include <vector>

class Word {
private:
    std::string secret;
    std::vector<bool> revealed;

public:
    Word(const std::string& word);
    bool Guess(char letter);
    void Display() const;
    bool IsFullyRevealed() const ;
    std::string GetSecret() const { return secret; } ;
};

