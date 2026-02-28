#include "pch.h"
#include "CppUnitTest.h"
#include "StudentC.h" // Adjust path as needed

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StudentTests
{
	TEST_CLASS(StudentC_Tests)
	{
	public:

		TEST_METHOD(IncreaseYear_WhenCalled_IncrementsYearByOne)
		{
			// --- Arrange ---
			StudentC student;
			int initialYear = 2023;
			student.setYear(initialYear);

			// --- Act ---
			student.increaseYear();

			// --- Assert ---
			int expectedYear = 2024;
			int actualYear = student.getYear();

			Assert::AreEqual(expectedYear, actualYear, L"The year did not increment correctly.");
		}
	};
}