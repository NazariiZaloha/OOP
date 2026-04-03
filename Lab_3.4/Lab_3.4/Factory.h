#ifndef FACTORY_H
#define FACTORY_H

#include "SymString.h"
#include "BinString.h"

class Factory {
public:
    static SymString* createSym(string id, string val);
    static BinString* createBin(string id, string val);
    static void destroy(SymString* obj);
};

#endif