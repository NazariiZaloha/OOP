#include "pch.h"
#include "CppUnitTest.h"

#include "Stack.h"
#include "Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(StackTests)
    {
    public:

        TEST_METHOD(Stack_Add_Remove)
        {
            Stack s;

            s.add(10);
            s.add(20);

            int result = s.remove();

            Assert::AreEqual(20, result); // LIFO
        }

        TEST_METHOD(Stack_Empty_Remove)
        {
            Stack s;

            int result = s.remove();

            Assert::AreEqual(-1, result); // перевірка пустого стеку
        }
    };

    TEST_CLASS(QueueTests)
    {
    public:

        TEST_METHOD(Queue_Add_Remove)
        {
            Queue q;

            q.add(10);
            q.add(20);

            int result = q.remove();

            Assert::AreEqual(10, result); // FIFO
        }

        TEST_METHOD(Queue_Multiple_Remove)
        {
            Queue q;

            q.add(1);
            q.add(2);
            q.add(3);

            q.remove(); // 1
            int result = q.remove(); // 2

            Assert::AreEqual(2, result);
        }

        TEST_METHOD(Queue_Empty_Remove)
        {
            Queue q;

            int result = q.remove();

            Assert::AreEqual(-1, result);
        }
    };
}