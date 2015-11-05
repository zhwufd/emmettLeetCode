#include <iostream>
#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid){
    vector<vector<int> > dp(obstacleGrid);
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[i].size(); j++){
            if(dp[i][j] == 1)
                dp[i][j] = -1;
        }
    }
    for(int i = 0; i < dp.size(); i++){
        for(int j = 0; j < dp[i].size(); j++){
            if(i == 0){
                if(j == 0){
                    if(dp[0][0] != -1)
                        dp[0][0] = 1;
                    else
                        break;
                }
                else{
                    if(dp[i][j] != -1)
                        dp[i][j] = dp[i][j-1];
                    else
                        break;
                }
            }
            else{
                if(dp[i][j] != -1){
                    if(j > 0 && dp[i][j-1] != -1)
                        dp[i][j] += dp[i][j-1];
                    if(dp[i-1][j] != -1)
                        dp[i][j] += dp[i-1][j];
                }
            }
        }
    }
    int res = dp.back().back();
    return (res == -1) ? 0: res;
}
            
int main(){
    vector<int> tmp(5,0);
    vector<vector<int> > grid(3,tmp);
    grid[0][3] = 1;
    grid[1][1] = 1;
    cout << uniquePathsWithObstacles(grid) << endl; 
    return 0;
}
