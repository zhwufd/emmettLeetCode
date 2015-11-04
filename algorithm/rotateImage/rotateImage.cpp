#include <iostream>
#include <vector>
using namespace std;


void rotate(vector<vector<int> >& matrix){
    int n = matrix.size();
    if(n > 1){
        int ncol = (n - 1)/2;
        int nrow = (n%2)?(ncol - 1): ncol;
        for(int i = 0; i <= nrow; i++){
            for(int j = 0; j <= ncol; j++){
                //rotate(i, j, n);
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-i-1] = tmp;
            }
        }
    }
}

void printVecVec(vector<vector<int> >& a){
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int aa[] = {1,2};
    vector<int> a(aa,aa+2);
    int bb[] = {3,4};
    vector<int> b(bb,bb+2);
    vector<vector<int> > matrix;
    matrix.push_back(a);
    matrix.push_back(b);
    printVecVec(matrix);
    rotate(matrix);
    cout << "after rotate: " << endl;
    printVecVec(matrix);
    return 0;
}
