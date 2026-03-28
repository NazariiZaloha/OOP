#include "D3.h"
D3::D3(int v1, int v2, int vd1, int vd2, int vd3)
    : D1(v1, v2, vd1), D2(vd2), d3(vd3) {
    std::cout << "Constructor D3\n";
}
D3::~D3() { std::cout << "Destructor D3\n"; }
void D3::show() {
    D1::show();
    D2::show();
    std::cout << "Class D3: d3 = " << d3 << std::endl;
}