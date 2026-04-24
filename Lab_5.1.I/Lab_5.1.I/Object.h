#pragma once

class Object {
private:
    static int count; // Static counter shared by all instances
public:
    Object();
    virtual ~Object(); // Virtual destructor is CRITICAL for inheritance
    static int getCount(); // Static method to access the counter
};