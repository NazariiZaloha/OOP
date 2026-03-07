#include <iostream>
#include "Goods.h"

using namespace std;

int main()
{
    Goods g1;
    cin >> g1;
    cout << g1 << endl;

    Goods g2(10.5, 4);
    cout << g2 << endl;

    Goods g3 = g2;
    cout << g3 << endl;

    g2++;
    ++g2;

    cout << "After ++ : " << g2 << endl;

    cout << "String: " << string(g2) << endl;

#pragma pack(push,1)
    cout << "Size with pack(1): " << sizeof(Goods) << endl;
#pragma pack(pop)

    cout << "Size normal: " << sizeof(Goods) << endl;

    return 0;
}