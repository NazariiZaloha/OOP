#include "BinString.h"
#include <iostream>
#include <bitset>
#include <sstream>
using namespace std;

BinString::BinString(string id, string val) : SymString(id, val) {}

int BinString::toDecimal() {
    return stoi(value, nullptr, 2);
}

void BinString::Show() {
    cout << "ID: " << id << " Binary: " << value << endl;
}

void BinString::ShowHex() {
    int dec = toDecimal();
    cout << "Hex: " << hex << dec << dec << endl;
}

BinString operator+(BinString& b1, BinString& b2) {
    int sum = b1.toDecimal() + b2.toDecimal();

    stringstream ss;
    ss << bitset<16>(sum);

    return BinString("result", ss.str());
}