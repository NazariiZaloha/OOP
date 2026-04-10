#ifndef SOLVER_H
#define SOLVER_H

#include "exceptions.h"

//
double solve_v1(double a, double b, double c);
double solve_v2(double a, double b, double c) throw();
double solve_v3(double a, double b, double c) throw(std::domain_error);
double solve_v4(double a, double b, double c) throw(EmptyException);
double solve_v5(double a, double b, double c);
double solve_v6(double a, double b, double c);

#endif