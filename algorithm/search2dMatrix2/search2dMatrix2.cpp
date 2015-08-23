#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector< vector<int> >& matrix, int target) {
        int nrow = matrix.size();
        if(nrow > 0) {
            int ncol = matrix[0].size();
            if(ncol > 0) {
                if(ncol <= nrow) {
                    int k = 0;
                    for(int i = nrow - 1; i >= 0; i--) {
                        for(int j = k; j < ncol; j++) {
                            if( matrix[i][j] == target )
                                return true;
                            else if(matrix[i][j] > target) {
                                k = j - 1;
                                break;
                            }
                        }
                        k = ( k < 0) ? 0 : k;
                    }
                }
                else {
                    int k = 0;
                    for(int i = ncol - 1; i >= 0; i--) {
                       for(int j = k; j < nrow; j++) {
                          if( matrix[j][i] == target )
                             return true;
                          else if(matrix[j][i] > target) {
                              k = j - 1;
                              break;
                          }
                       }
                       k = ( k < 0) ? 0 : k;
                    }
                }
            }
        }
        return false;
    }
};
