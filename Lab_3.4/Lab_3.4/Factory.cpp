#include "Factory.h"

SymString* Factory::createSym(string id, string val) {
    return new SymString(id, val);
}

BinString* Factory::createBin(string id, string val) {
    return new BinString(id, val);
}

void Factory::destroy(SymString* obj) {
    delete obj;
}