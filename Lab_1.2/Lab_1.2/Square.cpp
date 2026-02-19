#include "Square.h"
#include <cmath>
#include <cstdlib>

using namespace std;

Square::Square() : x1(0), y1(0), x2(0), y2(0) {}

bool Square::isValid(double ax1, double ay1, double ax2, double ay2) const
{
    double dx = ax2 - ax1;
    double dy = ay2 - ay1;

    double diagonal = sqrt(dx * dx + dy * dy);

    return diagonal > 0; // diagonal must not be zero
}

double Square::getX1() const { return x1; }
double Square::getY1() const { return y1; }
double Square::getX2() const { return x2; }
double Square::getY2() const { return y2; }

void Square::setX1(double value)
{
    if (!isValid(value, y1, x2, y2))
    {
        cout << "Invalid coordinates!" << endl;
        exit(1);
    }
    x1 = value;
}

void Square::setY1(double value)
{
    if (!isValid(x1, value, x2, y2))
    {
        cout << "Invalid coordinates!" << endl;
        exit(1);
    }
    y1 = value;
}

void Square::setX2(double value)
{
    if (!isValid(x1, y1, value, y2))
    {
        cout << "Invalid coordinates!" << endl;
        exit(1);
    }
    x2 = value;
}

void Square::setY2(double value)
{
    if (!isValid(x1, y1, x2, value))
    {
        cout << "Invalid coordinates!" << endl;
        exit(1);
    }
    y2 = value;
}

bool Square::Init(double ax1, double ay1, double ax2, double ay2)
{
    if (!isValid(ax1, ay1, ax2, ay2))
        return false;

    x1 = ax1;
    y1 = ay1;
    x2 = ax2;
    y2 = ay2;
    return true;
}

void Square::Read()
{
    double ax1, ay1, ax2, ay2;

    cout << "Enter x1: ";
    cin >> ax1;

    cout << "Enter y1: ";
    cin >> ay1;

    cout << "Enter x2: ";
    cin >> ax2;

    cout << "Enter y2: ";
    cin >> ay2;

    if (!Init(ax1, ay1, ax2, ay2))
    {
        cout << "Invalid square coordinates!" << endl;
        exit(1);
    }
}

double Square::sideLength() const
{
    double dx = x2 - x1;
    double dy = y2 - y1;

    double diagonal = sqrt(dx * dx + dy * dy);

    return diagonal / sqrt(2.0);
}

double Square::area() const
{
    double side = sideLength();
    return side * side;
}

double Square::perimeter() const
{
    return 4 * sideLength();
}

void Square::Display() const
{
    cout << "Diagonal coordinates: (" << x1 << ", " << y1 << ") and ("
        << x2 << ", " << y2 << ")" << endl;

    cout << "Side length: " << sideLength() << endl;
    cout << "Area: " << area() << endl;
    cout << "Perimeter: " << perimeter() << endl;
}

Square makeSquare(double ax1, double ay1, double ax2, double ay2)
{
    if (ax1 == ax2 && ay1 == ay2)
    {
        cout << "Error: Invalid square parameters!" << endl;
        exit(1);
    }

    Square s;

    if (!s.Init(ax1, ay1, ax2, ay2))
    {
        cout << "Error: Invalid square parameters!" << endl;
        exit(1);
    }

    return s;
}
