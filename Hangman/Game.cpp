#include "pch.h"

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
        player = Player();
        figure = Figure();
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
            system("cls");
        }
        std::cout << "You win! The word was: " << word.GetSecret() << std::endl;
    }

    std::string Game::GetWord(std::string filename) {

        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << '\n';
            return "";
        }

        std::vector<std::string> lines;
        std::string line;

        while (std::getline(file, line)) {
            lines.push_back(line);
        }

        file.close();

        if (lines.empty()) {
            std::cerr << "Error: File is empty.\n";
            return "";
        }

        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        int randomIndex = std::rand() % lines.size();

        return lines[randomIndex];
    }
}


