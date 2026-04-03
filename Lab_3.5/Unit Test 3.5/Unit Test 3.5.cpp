#include "pch.h"
#include "CppUnitTest.h"
#include "Decimal.h"  // adjust the path to Decimal.h

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DecimalTests
{
    TEST_CLASS(DecimalTests)
    {
    public:

        // Test that Decimal::toString() returns correct string for positive number
        TEST_METHOD(ToString_PositiveNumber)
        {
            Decimal num(12345);      // create Decimal with 12345
            std::string expected = "12345";
            std::string actual = num.toString();
            Assert::AreEqual(expected, actual);
        }

        // Test that Decimal::toString() returns correct string for negative number
        TEST_METHOD(ToString_NegativeNumber)
        {
            Decimal num(-6789);      // create Decimal with -6789
            std::string expected = "-6789";
            std::string actual = num.toString();
            Assert::AreEqual(expected, actual);
        }

        // Test that Decimal::toString() returns "0" for zero
        TEST_METHOD(ToString_Zero)
        {
            Decimal num(0);          // create Decimal with 0
            std::string expected = "0";
            std::string actual = num.toString();
            Assert::AreEqual(expected, actual);
        }
    };
}