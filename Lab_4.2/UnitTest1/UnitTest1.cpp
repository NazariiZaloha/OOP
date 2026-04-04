#include "pch.h"
#include "CppUnitTest.h"

#include "IList.h"
#include "Stack.h"
#include "Queue.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestProject
{
    TEST_CLASS(IListTests)
    {
    public:

        // 🔸 Поліморфізм через інтерфейс (Stack)
        TEST_METHOD(Polymorphism_Stack)
        {
            IList* list = new Stack();

            list->add(10);
            list->add(20);

            int result = list->remove();

            Assert::AreEqual(20, result); // LIFO

            delete list;
        }

        // 🔸 Поліморфізм через інтерфейс (Queue)
        TEST_METHOD(Polymorphism_Queue)
        {
            IList* list = new Queue();

            list->add(10);
            list->add(20);

            int result = list->remove();

            Assert::AreEqual(10, result); // FIFO

            delete list;
        }

        // 🔸 Масив поліморфних об’єктів (як у завданні)
        TEST_METHOD(Array_Of_Interface)
        {
            IList* arr[2];

            arr[0] = new Stack();
            arr[1] = new Queue();

            arr[0]->add(1);
            arr[0]->add(2);

            arr[1]->add(1);
            arr[1]->add(2);

            int stackResult = arr[0]->remove(); // 2
            int queueResult = arr[1]->remove(); // 1

            Assert::AreEqual(2, stackResult);
            Assert::AreEqual(1, queueResult);

            delete arr[0];
            delete arr[1];
        }

        // 🔸 Порожній контейнер
        TEST_METHOD(Empty_Remove)
        {
            IList* list = new Stack();

            int result = list->remove();

            Assert::AreEqual(-1, result);

            delete list;
        }

        // 🔸 Кілька операцій Queue
        TEST_METHOD(Queue_Multiple)
        {
            IList* list = new Queue();

            list->add(1);
            list->add(2);
            list->add(3);

            list->remove(); // 1
            int result = list->remove(); // 2

            Assert::AreEqual(2, result);

            delete list;
        }
    };
}