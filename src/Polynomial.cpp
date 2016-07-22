#include <cmath>
#include "Polynomial.h"

double Polynomial::evaluate(double x, std::vector<double> coefficients) {
    double y = 0;

    for (int i = 0; i < (int) coefficients.size(); i++) {
        y += coefficients[i] * pow(x, i);
    }

    return y;
}

