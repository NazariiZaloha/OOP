#include <iostream>
#include "solver.h"
#include "exceptions.h"

int main() {
    set_terminate(my_terminate);
    set_unexpected(my_unexpected);

    double a = 1, b = 2, c = 5; // D < 0

    // Приклад перехоплення для Варіанту 5
    try {
        solve_v5(a, b, c);
    }
    catch (const IndependentException& e) {
        std::cout << "Caught Independent: D = " << e.d << std::endl;
    }

    // Приклад перехоплення для Варіанту 6
    try {
        solve_v6(a, b, c);
    }
    catch (const DerivedException& e) {
        std::cout << "Caught Derived: " << e.what() << " Value: " << e.discriminant << std::endl;
    }

    // Демонстрація terminate (Варіант 2)
    std::cout << "Triggering unexpected behavior..." << std::endl;
    solve_v2(a, b, c);

    return 0;
}