#include "pch.h"
#include "CppUnitTest.h"
#include "Array.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ArrayTests
{
    TEST_CLASS(ArrayTests)
    {
    public:

        TEST_METHOD(ConstructorTest)
        {
            Array a(-2, 2);
            Assert::AreEqual(5, a.getSize());
        }

        TEST_METHOD(IndexingTest)
        {
            Array a(-1, 1);

            a[-1] = 10;
            a[0] = 20;
            a[1] = 30;

            Assert::AreEqual(10.0, a[-1]);
            Assert::AreEqual(20.0, a[0]);
            Assert::AreEqual(30.0, a[1]);
        }

        TEST_METHOD(IndexOutOfRangeTest)
        {
            Array a(0, 2);

            try {
                a[5];
                Assert::Fail(L"Expected exception not thrown");
            }
            catch (std::out_of_range&) {
                Assert::IsTrue(true);
            }
        }

        TEST_METHOD(SumTest)
        {
            Array a(0, 2);
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;

            Assert::AreEqual(6.0, a.sum());
        }

        TEST_METHOD(AverageTest)
        {
            Array a(0, 2);
            a[0] = 2;
            a[1] = 4;
            a[2] = 6;

            Assert::AreEqual(4.0, a.average());
        }

        TEST_METHOD(MaxMinTest)
        {
            Array a(0, 2);
            a[0] = -1;
            a[1] = 5;
            a[2] = 3;

            Assert::AreEqual(5.0, a.max());
            Assert::AreEqual(-1.0, a.min());
        }

        TEST_METHOD(AdditionTest)
        {
            Array a(0, 2);
            Array b(0, 2);

            for (int i = 0; i < 3; i++) {
                a[i] = i;
                b[i] = i;
            }

            Array c = a + b;

            Assert::AreEqual(0.0, c[0]);
            Assert::AreEqual(2.0, c[1]);
            Assert::AreEqual(4.0, c[2]);
        }

        TEST_METHOD(SubtractionTest)
        {
            Array a(0, 2);
            Array b(0, 2);

            a[0] = 3; a[1] = 3; a[2] = 3;
            b[0] = 1; b[1] = 1; b[2] = 1;

            Array c = a - b;

            Assert::AreEqual(2.0, c[0]);
            Assert::AreEqual(2.0, c[1]);
            Assert::AreEqual(2.0, c[2]);
        }

        TEST_METHOD(ScalarMultiplyTest)
        {
            Array a(0, 2);
            a[0] = 1; a[1] = 2; a[2] = 3;

            Array b = a * 2;

            Assert::AreEqual(2.0, b[0]);
            Assert::AreEqual(4.0, b[1]);
            Assert::AreEqual(6.0, b[2]);
        }

        TEST_METHOD(ScalarDivideTest)
        {
            Array a(0, 2);
            a[0] = 2; a[1] = 4; a[2] = 6;

            Array b = a / 2;

            Assert::AreEqual(1.0, b[0]);
            Assert::AreEqual(2.0, b[1]);
            Assert::AreEqual(3.0, b[2]);
        }

        TEST_METHOD(AssignmentTest)
        {
            Array a(0, 2);
            a[0] = 1; a[1] = 2; a[2] = 3;

            Array b;
            b = a;

            Assert::AreEqual(1.0, b[0]);
            Assert::AreEqual(2.0, b[1]);
            Assert::AreEqual(3.0, b[2]);
        }
    };
}