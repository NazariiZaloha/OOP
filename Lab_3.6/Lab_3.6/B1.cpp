#include "B1.h"
B1::B1(int val) : b1(val) { std::cout << "Constructor B1\n"; }
B1::~B1() { std::cout << "Destructor B1\n"; }
void B1::show() { std::cout << "Class B1: b1 = " << b1 << std::endl; }