#include "SymString.h"
#include <iostream>
using namespace std;

SymString::SymString(string id, string val) : id(id), value(val) {}

SymString::~SymString() {}

void SymString::Show() {
    cout << "ID: " << id << " Value: " << value << endl;
}

void SymString::ShowHex() {
    cout << "Hex: ";
    for (char c : value)
        cout << hex << (int)c << " ";
    
}

string SymString::getValue() const {
    return value;
}

SymString operator+(SymString& s1, SymString& s2) {
    return SymString("result", s1.value + s2.value);
}