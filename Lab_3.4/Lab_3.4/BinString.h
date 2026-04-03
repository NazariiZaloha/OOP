#ifndef BINSTRING_H
#define BINSTRING_H

#include "SymString.h"

class BinString : public SymString {
public:
    BinString(string id, string val);

    int toDecimal();
    void Show() override;
    void ShowHex() override;

    friend BinString operator+(BinString& b1, BinString& b2);
};

#endif