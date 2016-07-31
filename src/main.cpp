#include <iostream>
#include <vector>
#include "Solver.h"
#include "Polynomial.h"

using namespace std;

int main(int argc, char* argv[]) {
    const vector<vector<double>> f = {
            {0, 0, 1},
            {0, 0, 2}
    };

    const vector<vector<double>> dx = {
            Polynomial::derivative(f[0]),
            Polynomial::derivative(f[1]),
    };

    const vector<vector<double>> dxinv = {
            {0, -1. / 2., 0},
            {0, -1. / 4., 0}
    };

    const vector<double> constraint = {1, 1, -10};

    const double epsilon = 0.000001;

    Solver solver;
    solver.solve(f, dx, dxinv, constraint, epsilon);

    return 0;
}