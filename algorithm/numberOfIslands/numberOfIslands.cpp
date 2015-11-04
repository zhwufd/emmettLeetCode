#include <vector>
#include <iostream>
using namespace std;

void traversalIsland(int i, int j, vector<vector<char> >& grid){
    int nrow = grid.size();
    if(nrow > 0){
        int ncol = grid[0].size();
        if(grid[i][j] == '1'){
            grid[i][j] = '2';
            if( (i+1) < nrow)
                traversalIsland(i + 1, j, grid);
            if( (j+1) < ncol)
                traversalIsland(i, j+1, grid);
            if( (i-1) >= 0)
                traversalIsland(i-1, j, grid);
            if( (j-1) >= 0)
                traversalIsland(i, j-1, grid);
        }
    }
}

int numIslands(vector<vector<char> >& grid){
    int nrow = grid.size();
    int cnt = 0;
    if(nrow > 0){
        int ncol = grid[0].size();
        for(int i = 0; i < nrow; i++){
            for(int j = 0; j < ncol; j++){
                if(grid[i][j] == '1'){
                    traversalIsland(i, j, grid);
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int main(){
    char c[3][3] = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
    int nr = 3;
    int nc = 3;
    vector<vector<char> > grid;
    for(int i = 0; i < nr; i++){
        vector<char> t(c[i],c[i]+nc);
        grid.push_back(t);
    }
    cout << numIslands(grid)<<endl;
    return 0;
}
