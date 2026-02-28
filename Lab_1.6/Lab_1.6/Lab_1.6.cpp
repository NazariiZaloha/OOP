#include "StudentC.h"
#include <iostream>
using namespace std;

int main() {
    // Створюємо об'єкт студента
    StudentC student;

    // Зчитуємо дані студента з консолі
    cout << "Enter student information:" << endl;
    student.Read();

    // Відображаємо інформацію про студента
    cout << "\nStudent information:" << endl;
    student.Display();

    // Виводимо інформацію через toString
    cout << "\nStudent information (toString):" << endl;
    cout << student.toString();

    // Збільшуємо рік навчання
    student.increaseYear();

    // Показуємо змінений рік
    cout << "\nAfter increasing year:" << endl;
    student.Display();

    return 0;
}