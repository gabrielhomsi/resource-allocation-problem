#include <iostream>
#include <cmath>
#include <iomanip>
#include "Solver.h"
#include "Polynomial.h"

using namespace std;

void Solver::solve(const vector<vector<double>> &f, const vector<vector<double>> &dx,
                   const vector<vector<double>> &dxinv, const vector<double> &constraint, double epsilon) {
    this->f = &f;
    this->dx = &dx;
    this->dxinv = &dxinv;
    this->constraint = &constraint;
    this->epsilon = epsilon;

    cout.precision(10);

    binarySearch(0, -1 * constraint[constraint.size() - 1]);
}

void Solver::binarySearch(const double left, const double right) {
    const int num_variables = (int) f->size();

    const double middle = (left + right) / 2.;
    const double lambda = -1 * Polynomial::evaluate(middle, (*dx)[0]);

    cout << fixed << "lambda = " << lambda << ", ";

    double *xs = new double[num_variables];
    double error = 0;

    for (int i = 0; i < num_variables; i++) { // O(n)
        xs[i] = Polynomial::evaluate(lambda, (*dxinv)[i]);
        error += (*constraint)[i] * xs[i];

        cout << fixed << "xs[" << i << "] = " << xs[i] << ", ";
    }

    delete[] xs;

    error += (*constraint)[num_variables]; // - B

    cout << fixed << "error = " << abs(error) << endl;

    if (fabs(error) < epsilon) {
        return;
    }

    if (error > 0) {
        binarySearch(left, middle);
    } else {
        binarySearch(middle, right);
    }
}
