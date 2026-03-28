#include "D1.h"
D1::D1(int v1, int v2, int vd1) : B1(v1), B2(v2), d1(vd1) { std::cout << "Constructor D1\n"; }
D1::~D1() { std::cout << "Destructor D1\n"; }
void D1::show() {
    B1::show();
    B2::show();
    std::cout << "Class D1: d1 = " << d1 << std::endl;
}