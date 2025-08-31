#include "pch.h"
#include "CppUnitTest.h"
#include "../Hangman/Game.h"
#define TESTING
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace Hangman;

namespace HangmanTests
{
    TEST_CLASS(GameTests)
    {
    public:
        TEST_METHOD(GetWord_ReturnsEmptyString_WhenFileIsMissing)
        {

            Game game;

            std::string word = game.GetWord("NonExistentFile.txt");

            Assert::AreEqual(std::string(""), word, L"Expected empty string when file is missing.");
        }

        TEST_METHOD(GetWord_ReturnsEmptyString_WhenFileIsEmpty)
        {
            Game game;

            std::string word = game.GetWord("EmptyWordlist.txt");

            Assert::AreEqual(std::string(""), word, L"Expected empty string when file is empty.");
        }
    };
}
