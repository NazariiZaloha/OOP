#include "Stack.h"
#include "Queue.h"

int main() {
    List* arr[2];

    arr[0] = new Stack();
    arr[1] = new Queue();

    // Поліморфізм
    for (int i = 0; i < 2; i++) {
        arr[i]->printType();

        arr[i]->add(10);
        arr[i]->add(20);

        cout << "Removed: " << arr[i]->remove() << endl;
    }

    // очистка пам’яті
    for (int i = 0; i < 2; i++) {
        delete arr[i];
    }

    return 0;
}