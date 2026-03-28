#include "B2.h"
B2::B2(int val) : b2(val) { std::cout << "Constructor B2\n"; }
B2::~B2() { std::cout << "Destructor B2\n"; }
void B2::show() { std::cout << "Class B2: b2 = " << b2 << std::endl; }

