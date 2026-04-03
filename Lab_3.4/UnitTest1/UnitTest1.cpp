#include "pch.h"
#include "CppUnitTest.h"

#include "SymString.h"
#include "BinString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestSymStringPlus)
        {
            SymString s1("1", "hello");
            SymString s2("2", "world");

            SymString res = s1 + s2;

            Assert::AreEqual(std::string("helloworld"), res.getValue());
        }

        TEST_METHOD(TestBinStringPlus)
        {
            BinString b1("1", "1010"); // 10
            BinString b2("2", "0011"); // 3

            BinString res = b1 + b2;

            // очікуємо 13 → 1101 (може бути з нулями попереду)
            Assert::IsTrue(res.getValue().find("1101") != std::string::npos);
        }

        TEST_METHOD(TestBinToDecimal)
        {
            BinString b("1", "1010");

            int result = b.toDecimal();

            Assert::AreEqual(10, result);
        }

       

        TEST_METHOD(TestShowHex_NoCrash)
        {
            SymString s("1", "A");
            s.ShowHex();

            BinString b("2", "1111");
            b.ShowHex();

            Assert::IsTrue(true); // просто перевірка що не впало
        }
    };
}