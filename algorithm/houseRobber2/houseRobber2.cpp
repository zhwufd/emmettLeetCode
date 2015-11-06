int rob(vector<int>& nums, int m, int k){
    if(m > k)
        return 0;
    int n = nums.size();
    vector<int> dp(n,0);
    dp[m] = nums[m];
    for(int i = m + 1; i <= k; i++){
        if(i == (m+1))
            dp[m+1] = (nums[m+1] > dp[m])? nums[m+1] : dp[m];
        else{
            int c1 = dp[i-2] + nums[i];
            int c2 = dp[i-1];
            dp[i] = (c1 > c2)? c1 : c2;
        }
    }
    return dp[k];
}
int rob(vector<int>& nums){
    int n = nums.size();
    if(n <= 0)
        return 0;
    else if(n == 1)
        return nums[0];
    else if(n == 2)
        return (nums[0] > nums[1])?nums[0]:nums[1];
    else{
        int c1 = nums[0] + rob(nums, 2, n -2);
        int c2 = rob(nums, 1, n - 1);
        return (c1 > c2)? c1 : c2;
    }
}
