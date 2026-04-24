#include "pch.h"
#include "CppUnitTest.h"
#include "DigitalString.h" 
#include "Fraction.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectTests
{
    TEST_CLASS(DigitStringTests)
    {
    public:

        TEST_METHOD(Constructor_Default_SetsZero)
        {
            DigitString ds;
            Assert::AreEqual(std::string("0"), ds.getValue());
        }

        TEST_METHOD(Constructor_String_ValidInput)
        {
            DigitString ds("12345");
            Assert::AreEqual(std::string("12345"), ds.getValue());
        }

        TEST_METHOD(Constructor_String_InvalidInput_ThrowsException)
        {
            auto func = [] { DigitString ds("12a3"); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Operator_Increment_Prefix)
        {
            DigitString ds("10");
            ++ds;
            Assert::AreEqual(std::string("11"), ds.getValue());
        }

        TEST_METHOD(Operator_Addition_ReturnsCorrectSum)
        {
            DigitString a("50");
            DigitString b("25");
            DigitString res = a + b;
            Assert::AreEqual(std::string("75"), res.getValue());
        }
    };

    TEST_CLASS(FractionTests)
    {
    public:

        TEST_METHOD(Constructor_Parsing_ValidFormat)
        {
            Fraction f("10.50");
            Assert::AreEqual(std::string("10"), f.getValue());
            Assert::AreEqual((int)50, (int)f.getFractional());
        }

        TEST_METHOD(Constructor_Parsing_InvalidFormat_Throws)
        {
            auto func = [] { Fraction f("abc.def"); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(Operator_Plus_WithCarryOver)
        {
            // Testing logic: 0.600 + 0.500 = 1.100
            Fraction f1("0.600");
            Fraction f2("0.500");
            Fraction res = f1 + f2;

            Assert::AreEqual(std::string("1"), res.getValue());
            Assert::AreEqual((int)100, (int)res.getFractional());
        }

        TEST_METHOD(Operator_Greater_Comparison)
        {
            Fraction f1("10.5");
            Fraction f2("10.1");
            Assert::IsTrue(f1 > f2);
        }

        TEST_METHOD(ToString_MatchesExpectedFormat)
        {
            Fraction f("123.45");
            Assert::AreEqual(std::string("123.45"), f.toString());
        }
    };
}