
#pragma once

class Object {
    static int count;
public:
    Object();
    virtual ~Object();
    static int GetCount();
};