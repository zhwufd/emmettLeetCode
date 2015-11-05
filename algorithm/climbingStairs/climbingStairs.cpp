#include <iostream>
#include <vector>
using namespace std;

int climbStairs(int n){
    if(n == 0)
        return 0;
    vector<int> dp(n, 1);
    if(n > 1){
        for(int i = 1; i < n; i++){
            if(i == 1)
                dp[i] = 2;
            else
                dp[i] = dp[i-1] + dp[i-2];
        }
    }
    return dp.back();
}

int main(){
    for(int i = 0; i < 20; i++)
        cout << i << " " << climbStairs(i) << endl;
    return 0;
}
