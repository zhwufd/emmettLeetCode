#include <vector>
#include <iostream>
using namespace std;

vector<vector<int> > generateMatrix(int n) {
    if(n > 0){
        vector<int> tmp(n,0);
        vector<vector<int> > matrix(n,tmp);
        int cnt = 1;
        int flag = 0;
        int rmin = 0;
        int rmax = n - 1;
        int cmin = 0;
        int cmax = n - 1;
        int i = 0, j = 0;
        while(cnt <= n*n){
            while( i >= rmin && i <= rmax && j >= cmin && j <= cmax){
                matrix[i][j] = cnt;
                ++cnt;
                switch(flag){
                    case 0:
                        j++;
                        break;
                    case 1:
                        i++;
                        break;
                    case 2:
                        j--;
                        break;
                    case 3:
                        i--;
                }
            }
            switch(flag){
                case 0:
                    ++rmin;
                    i = rmin;
                    j = cmax;
                    break;
                case 1:
                    --cmax;
                    j = cmax;
                    i = rmax;
                    break;
                case 2:
                    --rmax;
                    i = rmax;
                    j = cmin;
                    break;
                case 3:
                    ++cmin;
                    j = cmin;
                    i = rmin;
            }
            ++flag;
            flag = flag % 4;
        }
        return matrix;
    }
    else{
        vector<vector<int> > matrix;
        return matrix;
    }
}

void printMatrix(vector<vector<int> >& matrix){
    for(int i = 0; i< matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int n = 10;
    vector<vector<int> > matrix = generateMatrix(n);
    printMatrix(matrix);
    return 0;
}
