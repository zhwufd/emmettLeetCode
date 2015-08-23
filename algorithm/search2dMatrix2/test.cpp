#include "search2dMatrix2.cpp"
#include <vector>
using namespace std;

int main() {
    vector< vector<int> > matrix(1, vector<int>(2, 0));
    matrix[0][0] = -1;
    matrix[0][1] = 3;
    Solution sol;
    int res = sol.searchMatrix(matrix, 1);
    return 0;
}
