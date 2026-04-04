#include "Decimal.h"
#include "BitString.h"

void inputDecimal(Decimal& d) {
    std::cout << "Enter digits from least significant to most significant:\n";
    for (int i = 0; i < d.getSize(); i++) {
        int digit;
        std::cin >> digit;
        d[i] = digit;
    }
    std::cout << "Enter sign (1 or -1): ";
    std::cin >> d.sign;
}

void inputBitString(BitString& b) {
    std::cout << "Enter bits from least significant to most significant:\n";
    for (int i = 0; i < b.getSize(); i++) {
        int bit;
        std::cin >> bit;
        b[i] = bit;
    }
}

int main() {
    Array* arr[2];

    std::cout << "Choose type for first object (1-Decimal, 2-BitString): ";
    int choice; std::cin >> choice;
    if (choice == 1) arr[0] = new Decimal(3);
    else arr[0] = new BitString(3);

    std::cout << "Choose type for second object (1-Decimal, 2-BitString): ";
    std::cin >> choice;
    if (choice == 1) arr[1] = new Decimal(3);
    else arr[1] = new BitString(3);

    // input
    if (arr[0]->getType() == std::string("Decimal")) inputDecimal(*dynamic_cast<Decimal*>(arr[0]));
    else inputBitString(*dynamic_cast<BitString*>(arr[0]));

    if (arr[1]->getType() == std::string("Decimal")) inputDecimal(*dynamic_cast<Decimal*>(arr[1]));
    else inputBitString(*dynamic_cast<BitString*>(arr[1]));

    // демонстрація поліморфізму
    Array* result = arr[0]->add(*arr[1]);
    std::cout << "Result type: " << result->getType() << "\n";
    result->print();

    delete arr[0];
    delete arr[1];
    delete result;
    return 0;
}








/*
Приклад запуску програми:

--- Сценарій 1: Decimal + Decimal ---
Choose type for first object (1-Decimal, 2-BitString): 1
Enter digits from least significant to most significant:
5 2 1
Enter sign (1 or -1): 1

Choose type for second object (1-Decimal, 2-BitString): 1
Enter digits from least significant to most significant:
7 3 4
Enter sign (1 or -1): 1

Result type: Decimal
468
------------------------------

--- Сценарій 2: BitString + BitString ---
Choose type for first object (1-Decimal, 2-BitString): 2
Enter bits from least significant to most significant:
1 0 1 1
Choose type for second object (1-Decimal, 2-BitString): 2
Enter bits from least significant to most significant:
0 1 1 0

Result type: BitString
1101
------------------------------

Примітки:
- Для Decimal: цифри вводяться **з молодшого розряду до старшого** (одиниці → десятки → сотні)
- Для BitString: біти вводяться **з молодшого до старшого** (молодший біт = data[0])
- Decimal виводиться у звичному порядку чисел (старший розряд перший)
- BitString виводиться від старшого біта до молодшого
*/