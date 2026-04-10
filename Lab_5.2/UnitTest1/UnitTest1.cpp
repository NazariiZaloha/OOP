#include "pch.h"
#include "CppUnitTest.h"
#include "solver.h"     // Шлях до ваших заголовочних файлів
#include "exceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab52Tests
{
	TEST_CLASS(SolverTests)
	{
	public:

		// Тест на випадок, коли дискримінант додатний (немає винятку)
		TEST_METHOD(TestPositiveDiscriminant)
		{
			double a = 1, b = 5, c = 4; // D = 25 - 16 = 9
			double root = solve_v1(a, b, c);
			Assert::AreEqual(-1.0, root); // Перевіряємо один з коренів
		}

		// Тест Варіанту 3: Стандартна виняткова ситуація
		TEST_METHOD(TestV3_StandardException)
		{
			auto func = [] { solve_v3(1, 2, 5); };
			Assert::ExpectException<std::domain_error>(func);
		}

		// Тест Варіанту 4: Порожній клас
		TEST_METHOD(TestV4_EmptyClass)
		{
			auto func = [] { solve_v4(1, 2, 5); };
			Assert::ExpectException<EmptyException>(func);
		}

		// Тест Варіанту 5: Незалежний клас (перевірка значень всередині помилки)
		TEST_METHOD(TestV5_IndependentClassFields)
		{
			try {
				solve_v5(1, 2, 5); // D = -16
				Assert::Fail(L"Exception was not thrown");
			}
			catch (const IndependentException& e) {
				Assert::AreEqual(-16.0, e.d);
				Assert::AreEqual(1.0, e.a);
			}
		}

		// Тест Варіанту 6: Нащадок std::exception
		TEST_METHOD(TestV6_DerivedException)
		{
			auto func = [] { solve_v6(1, 2, 5); };
			Assert::ExpectException<DerivedException>(func);
		}
	};
}