#include "pch.h" // для Unit Test Project
#include "CppUnitTest.h"
#include "Student.h" // вкажи правильний шлях

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestStudent
{
    TEST_CLASS(StudentTests)
    {
    public:

        TEST_METHOD(TestIncreaseYear)
        {
            Student s;
            s.setYear(1); // початковий рік
            s.increaseYear();

            // перевіряємо, що рік збільшився на 1
            Assert::AreEqual(2, s.getYear());

            // ще раз перевіряємо
            s.increaseYear();
            Assert::AreEqual(3, s.getYear());
        }
    };
}