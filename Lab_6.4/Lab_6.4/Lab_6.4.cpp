#include <iostream>
using namespace std;

// 🔷 Шаблон функції сортування (Bubble Sort)
template <typename T>
void bubbleSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // обмін
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 🔷 Допоміжна функція виводу (теж шаблон)
template <typename T>
void printArray(T arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    // 🔹 Інстанціювання для int
    int arr1[] = { 5, 2, 9, 1, 3 };
    int size1 = 5;

    cout << "Before sorting (int): ";
    printArray(arr1, size1);

    bubbleSort(arr1, size1);

    cout << "After sorting (int): ";
    printArray(arr1, size1);

    cout << endl;

    // 🔹 Інстанціювання для double
    double arr2[] = { 3.5, 1.2, 4.8, 2.1 };
    int size2 = 4;

    cout << "Before sorting (double): ";
    printArray(arr2, size2);

    bubbleSort(arr2, size2);

    cout << "After sorting (double): ";
    printArray(arr2, size2);

    return 0;
}