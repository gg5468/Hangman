#pragma once
#include <string>
#include <vector>

class Word {
private:
    std::string secret;
    std::vector<bool> revealed;

public:
    Word(const std::string& word);
    bool const Guess(char letter);
    void const Display();
    bool const IsFullyRevealed();
    std::string const GetSecret() { return secret; };
};

