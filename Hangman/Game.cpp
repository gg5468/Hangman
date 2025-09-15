#include "Game.h"
#include "Word.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

namespace Hangman {
    Game::Game()
    {
    }

    void Game::Run()
    {
        Word word(GetWord("Wordlist.txt"));

        while (!word.IsFullyRevealed())
        {
            if (figure.GetBodyParts() >= 6) {
                std::cout << "Game Over! The word was: " << word.GetSecret() << std::endl;
                return;
            }

            figure.Display();
            word.Display();
            char guess = player.GetUserInput(std::cin);

            auto res = word.Guess(guess);
            if (!res) {
                figure.AddBodyPart();
            }
            std::cout << "\033[2J\033[1;1H"; //clear console
        }
        std::cout << "You win! The word was: " << word.GetSecret() << std::endl;
    }

    std::vector<std::string> Game::getLines(std::ifstream& file) {
        std::vector<std::string> lines;
        std::string line;
        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        return lines;
	}

    std::string Game::GetWord(std::string filename) {

        std::ifstream file(filename);
        if (!file.is_open()) {
            return "";
        }

        std::vector<std::string> lines = getLines(file);
        if (lines.empty()) {
            return "";
        }

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int randomIndex = std::rand() % lines.size();

        return lines[randomIndex];
    }
}


