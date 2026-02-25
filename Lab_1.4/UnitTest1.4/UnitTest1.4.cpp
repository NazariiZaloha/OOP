#include "pch.h"
#include "CppUnitTest.h"
#include "Complex.h"   // шлях до твого заголовочного файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ComplexUnitTest
{
	TEST_CLASS(ComplexTests)
	{
	public:

		TEST_METHOD(TestMultiply)
		{
			// Arrange
			Complex a(2, 3);   // 2 + 3i
			Complex b(4, -5);  // 4 - 5i

			// Act
			Complex result = a.multiply(b);

			// (2 + 3i)(4 - 5i)
			// = 2*4 - 3*(-5)  +  (2*(-5) + 3*4)i
			// = 8 + 15  + (-10 + 12)i
			// = 23 + 2i

			// Assert
			Assert::AreEqual(23.0, result.getReal());
			Assert::AreEqual(2.0, result.getImag());
		}
	};
}