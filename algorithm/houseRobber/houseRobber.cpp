int rob(vector<int>& nums){
    int n = nums.size();
    if(n <= 0)
        return 0;
    vector<int> dp(n,0);
    dp[0] = nums[0];
    for(int i = 1; i < n; i++){
        if(i == 1)
            dp[1] = (nums[1] > dp[0])? nums[1] : dp[0];
        else{
            int c1 = dp[i-2] + nums[i];
            int c2 = dp[i-1];
            dp[i] = (c1 > c2)? c1 : c2;
        }
    }
    return dp.back();
}
