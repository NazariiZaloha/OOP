#pragma once
#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

class Square
{
private:
    double x1, y1;
    double x2, y2;

    bool isValid(double ax1, double ay1, double ax2, double ay2) const;

public:
    Square();

    // Getters (const)
    double getX1() const;
    double getY1() const;
    double getX2() const;
    double getY2() const;

    // Setters with validation
    void setX1(double value);
    void setY1(double value);
    void setX2(double value);
    void setY2(double value);

    bool Init(double ax1, double ay1, double ax2, double ay2);

    void Read();
    void Display() const;

    double sideLength() const;
    double area() const;
    double perimeter() const;
};

Square makeSquare(double ax1, double ay1, double ax2, double ay2);

#endif
