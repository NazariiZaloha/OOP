#include "D2.h"
D2::D2(int val) : d2(val) { std::cout << "Constructor D2\n"; }
D2::~D2() { std::cout << "Destructor D2\n"; }
void D2::show() { std::cout << "Class D2: d2 = " << d2 << std::endl; }