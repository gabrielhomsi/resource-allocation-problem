#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include "Solver.h"

using namespace std;

int main() {
    vector<vector<double>> f = {
            {0, 0, 1},
            {0, 0, 2}
    };

    vector<vector<double>> dx = {
            {0, 2, 0},
            {0, 4, 0}
    };

    vector<vector<double>> dxinv = {
            {0, -1. / 2., 0},
            {0, -1. / 4., 0}
    };

    vector<double> constraint = {1, 1, -10};

    double epsilon = 0.0001;

    Solver solver;
    solver.solve(f, dx, dxinv, constraint, epsilon);

    return 0;
}