#include "Square.h"

int main()
{
    Square s1 = makeSquare(0, 0, 4, 4);
    s1.Display();

    Square s2;
    s2.Read();
    s2.Display();

    return 0;
}
