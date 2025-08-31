#include "pch.h"
#include "../Hangman/Player.h"
#include <CppUnitTest.h>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(PlayerInputTests)
    {
    public:

        TEST_METHOD(ValidInput_ReturnsCharacter)
        {
            std::istringstream input("a\n");
            Player player;
            char result = player.GetUserInput(input);
            Assert::AreEqual('a', result);
        }

        TEST_METHOD(InvalidThenValidInput_ReturnsValidCharacter)
        {
            std::istringstream input("1\nb\n");
            Player player;
            char result = player.GetUserInput(input);
            Assert::AreEqual('b', result);
        }

        TEST_METHOD(UppercaseInput_ReturnsUppercaseCharacter)
        {
            std::istringstream input("Z\n");
            Player player;
            char result = player.GetUserInput(input);
            Assert::AreEqual('Z', result);
        }

        TEST_METHOD(MultipleCharactersInput_ThenValidInput_ReturnsValidCharacter)
        {
            std::istringstream input("abc\nx\n");
            Player player;
            char result = player.GetUserInput(input);
            Assert::AreEqual('x', result);
        }
    };
}