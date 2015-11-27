#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minDistance(string word1, string word2){
    int len1 = word1.length();
    int len2 = word2.length();
    vector<int> tmp(len2 + 1, 0);
    vector<vector<int> > dp(len1 + 1, tmp);
    for(int i = 0; i <= len1; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= len2; j++){
        dp[0][j] = j;
    }
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            int t1 = (dp[i][j-1] < dp[i-1][j])? dp[i][j-1] : dp[i-1][j];
            ++t1;
            int t2 = (word1[i-1] == word2[j-1])? dp[i-1][j-1] :(dp[i-1][j-1] + 1);
            dp[i][j] = (t1 > t2)? t2 : t1;
        }
    }
    return dp[len1][len2];
}

int main(){
    string wd1 = "hello";
    string wd2 = "halo";
    cout << minDistance(wd1, wd2) << " " << wd1 << " " << wd2 << endl;
    return 0;
}
