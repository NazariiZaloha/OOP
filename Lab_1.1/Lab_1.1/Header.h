#pragma once
#ifndef GOODS_H
#define GOODS_H

#include <iostream>

class Goods
{
private:
    double first;   // ціна (додатне дробове)
    int second;     // кількість (додатне ціле)

public:
    // Конструктор за замовчуванням
    Goods();

    // Методи доступу (get – const)
    double getFirst() const;
    int getSecond() const;

    // Методи запису (з перевіркою)
    void setFirst(double value);
    void setSecond(int value);

    // Ініціалізація
    bool Init(double price, int quantity);

    // Ввід / Вивід
    void Read();
    void Display() const;

    // Обчислення вартості
    double cost() const;
};

// Зовнішня функція створення об'єкта
Goods makeGoods(double price, int quantity);

#endif
