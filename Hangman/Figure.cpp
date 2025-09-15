#include "Figure.h"
#include <iostream>
#include <vector>

Figure::Figure(){
    body_parts = 0;
}

void Figure::AddBodyPart() {
    if (body_parts < 6) {
        ++body_parts;
    }
}

void Figure::Display() {
    std::vector<std::string> hangman = {
        "  _______     ",
        " |/      |    ",
        " |      " + std::string((body_parts >= 1) ? "O" : " "),
        " |     " + std::string((body_parts >= 3) ? "/" : " ") +
                  std::string((body_parts >= 2) ? "|" : " ") +
                  std::string((body_parts >= 4) ? "\\" : " "),
        " |     " + std::string((body_parts >= 5) ? "/" : " ") +
                  std::string((body_parts >= 6) ? " \\" : "  "),
        " |            ",
        "_|___         "
    };

    for (const auto& line : hangman) {
        std::cout << line << '\n';
    }
    std::cout << std::endl;
}