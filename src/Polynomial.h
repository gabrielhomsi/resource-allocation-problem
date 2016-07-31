#ifndef RAP_POLYNOMIAL_H
#define RAP_POLYNOMIAL_H


#include <vector>

using namespace std;

class Polynomial {
public:
    static double evaluate(const double x, const vector<double> coefficients);

    static vector<double> derivative(const vector<double> coefficients);
};


#endif //RAP_POLYNOMIAL_H
