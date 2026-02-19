#include "Header.h"

int main()
{
    // Створення через makeGoods
    Goods g1 = makeGoods(10.5, 3);
    g1.Display();

    // Ввід з клавіатури
    Goods g2;
    g2.Read();
    g2.Display();

    return 0;
}
