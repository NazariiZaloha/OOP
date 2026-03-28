#include "pch.h"
#include "CppUnitTest.h"
#include "D1.h" // Шлях до вашого файлу
#include "B1.h"
#include "B2.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectTests
{
    TEST_CLASS(HierarchyTests)
    {
    public:

        // Тест перевірки ініціалізації полів через конструктор
        TEST_METHOD(TestMethodD1Constructor)
        {
            // Arrange (Підготовка)
            int valB1 = 5, valB2 = 10, valD1 = 15;

            // Act (Дія)
            D1 obj(valB1, valB2, valD1);

            // Assert (Перевірка результату)
            Assert::AreEqual(valB1, obj.getB1());
            Assert::AreEqual(valD1, obj.getD1());
        }

    };
}