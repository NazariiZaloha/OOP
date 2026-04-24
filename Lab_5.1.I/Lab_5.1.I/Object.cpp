#include "Object.h"

int Object::count = 0; // Initialize static member

Object::Object() { count++; }
Object::~Object() { count--; }
int Object::getCount() { return count; }