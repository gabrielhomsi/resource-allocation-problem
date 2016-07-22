#include <iostream>
#include <cmath>
#include "Solver.h"
#include "Polynomial.h"

using namespace std;

void Solver::solve(vector<vector<double>> &f, vector<vector<double>> &dx,
                   vector<vector<double>> &dxinv, vector<double> &constraint, double epsilon) {
    binarySearch(0, -1 * constraint[constraint.size() - 1], f, dx, dxinv, constraint, epsilon);
}

void Solver::binarySearch(double left, double right, vector<vector<double>> &f,
                          vector<vector<double>> &dx,
                          vector<vector<double>> &dxinv, vector<double> &constraint, double epsilon) {
    int num_variables = (int) f.size();

    double middle = (left + right) / 2.;
    double lambda = -1 * Polynomial::evaluate(middle, dx[0]);

    double *xs = new double[num_variables];
    double error = 0;

    for (int i = 0; i < num_variables; i++) {
        xs[i] = Polynomial::evaluate(lambda, dxinv[i]);
        error += constraint[i] * xs[i];

        cout << xs[i] << ", ";
    }

    error += constraint[num_variables];

    delete[] xs;

    cout << error << endl;

    if (fabs(error) < epsilon) {
        return;
    }

    if (error > 0) {
        binarySearch(left, middle, f, dx, dxinv, constraint, epsilon);
    } else {
        binarySearch(middle, right, f, dx, dxinv, constraint, epsilon);
    }
}
