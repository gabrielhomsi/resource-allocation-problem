#ifndef RAP_SOLVER_H
#define RAP_SOLVER_H


#include <vector>

using namespace std;

class Solver {
public:
    void solve(vector<vector<double>> &f, vector<vector<double>> &dx,
               vector<vector<double>> &dxinv, vector<double> &constraint, double epsilon);

private:
    void binarySearch(double left, double right, vector<vector<double>> &f,
                      vector<vector<double>> &dx,
                      vector<vector<double>> &dxinv, vector<double> &constraint, double epsilon);
};


#endif //RAP_SOLVER_H
