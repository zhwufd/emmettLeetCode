#include <vector>
#include <iostream>
using namespace std;

void setRowZeroes(vector<vector<int> >& matrix, int i){
    int nrow = matrix.size();
    if(nrow <= i)
        return;
    int ncol = matrix[0].size();
    if(ncol == 0)
        return;
    for(int j = 0; j < ncol; j++)
        matrix[i][j] = 0;
}

void setColZeroes(vector<vector<int> >& matrix, int j){
    int nrow = matrix.size();
    if(nrow == 0)
        return;
    int ncol = matrix[0].size();
    if(ncol <= j)
        return;
    for(int i = 0; i < nrow; i++)
        matrix[i][j] = 0;
}

void setFull(vector<vector<int> >& matrix){
    int nrow = matrix.size();
    for(int i = 0; i < nrow; i++){
        setRowZeroes(matrix, i);
    }
}
void setZeroes(vector<vector<int> >& matrix){
    int nrow = matrix.size();
    if(nrow == 0)
        return;
    int ncol = matrix[0].size();
    if(ncol == 0)
        return;
    int irow = -1;
    for(int i = 0; i < nrow; i++){
        int j = 0;
        for(; j < ncol; j++){
            if(matrix[i][j] == 0)
                break;
        }
        if(j == ncol){
            irow = i;
            break;
        }
    }
    if(irow == -1){
        setFull(matrix);
        return;
    }
    int icol = -1;
    for(int i = 0; i < ncol; i++){
        int j = 0;
        for(; j < nrow; j++){
            if(matrix[j][i] == 0)
                break;
        }
        if(j == nrow){
            icol = i;
            break;
        }
    }
    if(icol == -1){
        setFull(matrix);
        return;
    }
    for(int i = 0; i < nrow; i++){
        if(i == irow)
            continue;
        for(int j = 0; j < ncol; j++){
            if(j == icol)
                continue;
            if(matrix[i][j] == 0){
                matrix[irow][j] = 0;
                matrix[i][icol] = 0;
            }
        }
    }
    for(int i = 0; i < nrow; i++){
        if(matrix[i][icol] == 0)
            setRowZeroes(matrix, i);
    }
    for(int j = 0; j < ncol; j++){
        if(matrix[irow][j] == 0)
            setColZeroes(matrix, j);
    }
    return;
}
