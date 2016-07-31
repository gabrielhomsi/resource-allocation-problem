#ifndef RAP_SOLVER_H
#define RAP_SOLVER_H


#include <vector>

using namespace std;

class Solver {
public:
    void solve(const vector<vector<double>> &f, const vector<vector<double>> &dx,
               const vector<vector<double>> &dxinv, const vector<double> &constraint, const double epsilon);

private:
    const vector<vector<double>> *f = nullptr;
    const vector<vector<double>> *dx = nullptr;
    const vector<vector<double>> *dxinv = nullptr;
    const vector<double> *constraint = nullptr;
    double epsilon;

    void binarySearch(const double left, const double right);
};


#endif //RAP_SOLVER_H
