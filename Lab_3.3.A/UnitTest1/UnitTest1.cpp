#include "pch.h"
#include "CppUnitTest.h"
#include "Rational.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRational
{
    TEST_CLASS(UnitTestRational)
    {
    public:

        TEST_METHOD(TestAdd)
        {
            // Arrange (підготовка)
            Rational r1(1, 2);
            Rational r2(1, 3);

            // Act (дія)
            Rational result = r1.add(r2);

            // Assert (перевірка)
            Assert::AreEqual(5, result.getA());
            Assert::AreEqual(6, result.getB());
        }
    };
}