class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        vector<bool> exists(n + 1,false);
        for(int i = 0; i < n; i++){
            exists[nums[i]] = true;
        }
        for(int j = 0; j <= n; j++){
            if(!exists[j])
                return j;
        }
    }
};
