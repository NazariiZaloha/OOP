
#include "Student.h"

using namespace std;

int main()
{
    // створюємо людину
    Man m;
    m.Init("Nazar", "male", 18, 70);

    // створюємо студента
    Student s;
    s.Init(1, m);

   
    s.Display();

    // змінюємо дані людини
    m.setName("Oleh");
    m.setAge(19);
    m.setWeight(75);

    // оновлюємо студента
    s.setMan(m);

    // збільшуємо рік навчання
    s.increaseYear();

    
    s.Display();

    return 0;
}