//
// Created by mazur on 11.11.2020.
//

#ifndef EXCEPTIONS_EXCEP_H
#define EXCEPTIONS_EXCEP_H

#include <iostream>

class ZeroDivisionError {
public:
    float ErrorPoint;
    ZeroDivisionError();
    ZeroDivisionError(float);
};

float div(float, float);
void task1_var3();

#endif //EXCEPTIONS_EXCEP_H
