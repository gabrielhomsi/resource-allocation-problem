#include <cmath>
#include "Polynomial.h"

using namespace std;

double Polynomial::evaluate(const double x, const vector<double> coefficients) {
    double y = 0;

    for (int i = 0; i < (int) coefficients.size(); i++) {
        y += coefficients[i] * pow(x, i);
    }

    return y;
}

vector<double> Polynomial::derivative(const vector<double> coefficients) {
    vector<double> result;
    result.resize(coefficients.size() - 1);

    for (int i = 0; i < (int) result.size(); i++) {
        result[i] = (i + 1) * coefficients[i + 1];
    }

    return result;
}