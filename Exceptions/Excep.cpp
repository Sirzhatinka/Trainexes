//
// Created by mazur on 11.11.2020.
//

#include "Excep.h"

ZeroDivisionError::ZeroDivisionError(): ErrorPoint(0) { }
ZeroDivisionError::ZeroDivisionError(float ErrP): ErrorPoint(ErrP) { }

float div(float a, float b) {
    if (!b)
        throw ZeroDivisionError();
    return a / b;
}

void task1_var3() {
    char answer;
    float first, second;
    do {
        std::cout << "Your numbers: ";
        std::cin >> first >> second;
        try {
            std::cout << "Result: " << div(first, second);
        }
        catch (ZeroDivisionError& err) {
            std::cerr << "\nZero division error! Try again\n";
        }
        std::cout << "\nElse? y/n: ";
        std::cin >> answer;
    } while (answer == 'y');
    system("pause");
}