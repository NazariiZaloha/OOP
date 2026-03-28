#include "D4.h"
D4::D4(int v1, int v2, int vd1, int vd2, int vd3, int vd4)
    : D3(v1, v2, vd1, vd2, vd3), d4(vd4) {
    std::cout << "Constructor D4\n";
}
D4::~D4() { std::cout << "Destructor D4\n"; }
void D4::show() {
    D3::show();
    std::cout << "Class D4: d4 = " << d4 << std::endl;
}