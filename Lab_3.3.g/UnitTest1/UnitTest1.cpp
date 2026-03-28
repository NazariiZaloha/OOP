#include "pch.h"
#include "CppUnitTest.h"
#include "Fraction.h"
#include "DigitString.h"
#include "Object.h"

// Примітка: замініть YourProjectName на назву вашої папки з вихідним кодом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTests
{
	TEST_CLASS(FractionTests)
	{
	public:

		TEST_METHOD(TestObjectCounter)
		{
			int initialCount = Object::GetCount();
			Fraction* f = new Fraction("10", 5);
			Assert::AreEqual(initialCount + 1, Object::GetCount());
			delete f;
			Assert::AreEqual(initialCount, Object::GetCount());
		}

		TEST_METHOD(TestDigitStringInitialization)
		{
			DigitString ds;
			bool result = ds.Init("12345");
			Assert::IsTrue(result);
			Assert::AreEqual(std::string("12345"), ds.GetValue());

			bool invalidResult = ds.Init("12a45"); // Містить літеру
			Assert::IsFalse(invalidResult);
		}

		TEST_METHOD(TestFractionAddition)
		{
			Fraction f1("10", 500); // 10.500
			Fraction f2("5", 600);  // 5.600

			// Очікуємо 10.5 + 5.6 = 16.1 (або 16.100)
			// У нашій логіці: 500 + 600 = 1100 -> перенос 1 до цілої частини, залишок 100
			Fraction sum = f1 + f2;

			Assert::AreEqual(std::string("16.100"), sum.toString());
		}

		TEST_METHOD(TestFractionComparison)
		{
			Fraction f1("20", 100);
			Fraction f2("10", 999);

			Assert::IsTrue(f1 > f2); // 20.100 > 10.999
		}

		TEST_METHOD(TestIncrement)
		{
			Fraction f("10", 500);
			++f; // Префіксний інкремент цілої частини
			Assert::AreEqual(std::string("11.500"), f.toString());
		}
	};
}