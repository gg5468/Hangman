#include "pch.h"
#include "../Hangman/Word.h"
#include <CppUnitTest.h>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
    TEST_CLASS(WordTests)
    {
    public:

        TEST_METHOD(CorrectGuess_RevealsLetter)
        {
            Word word("test");
            bool result = word.Guess('t');
            Assert::IsTrue(result);
            Assert::IsTrue(word.IsFullyRevealed() == false);
        }

        TEST_METHOD(IncorrectGuess_ReturnsFalse)
        {
            Word word("hello");
            bool result = word.Guess('z');
            Assert::IsFalse(result);
            Assert::IsFalse(word.IsFullyRevealed());
        }

        TEST_METHOD(CaseInsensitiveGuess_Works)
        {
            Word word("Apple");
            bool resultLower = word.Guess('a');
            bool resultUpper = word.Guess('P');
            Assert::IsTrue(resultLower);
            Assert::IsTrue(resultUpper);
        }

        TEST_METHOD(MultipleOccurrences_AreRevealed)
        {
            Word word("banana");
            bool result = word.Guess('a');
            Assert::IsTrue(result);
            Assert::IsFalse(word.IsFullyRevealed());
        }

        TEST_METHOD(IsFullyRevealed_TrueWhenAllGuessed)
        {
            Word word("hi");
            word.Guess('h');
            word.Guess('i');
            Assert::IsTrue(word.IsFullyRevealed());
        }
    };
}
