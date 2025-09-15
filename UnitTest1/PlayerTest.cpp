#include "../Hangman/Player.cpp"
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
            Assert::AreEqual('a', player.GetUserInput(input));
        }

        TEST_METHOD(InvalidThenValidInput_ReturnsValidCharacter)
        {
            std::istringstream input("1\nb\n");
            Player player;
            Assert::AreEqual('b', player.GetUserInput(input));
        }

        TEST_METHOD(UppercaseInput_ReturnsUppercaseCharacter)
        {
            std::istringstream input("Z\n");
            Player player;
            Assert::AreEqual('Z', player.GetUserInput(input));
        }

        TEST_METHOD(MultipleCharactersInput_ThenValidInput_ReturnsValidCharacter)
        {
            std::istringstream input("abc\nx\n");
            Player player;
            Assert::AreEqual('x', player.GetUserInput(input));
        }
    };
}