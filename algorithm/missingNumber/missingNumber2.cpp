class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int r = n%4;
            int m = n - r;
            if(m > 0) {
                int s = 0;
                bool flag0 = false;
                for(int i = 0; i < n; i++) {
                    if(nums[i] < m)
                        s = s^nums[i];
                    if(nums[i] == 0)
                        flag0 = true;
                }
                if(s != 0)
                    return s;
                else if(!flag0)
                    return 0;
            }
            vector<bool> exists(r + 1, false);
            for(int i = 0; i < n; i++) {
                if(nums[i] >= m)
                    exists[nums[i]%4] = true;
            }
            for(int i = 0; i <= r; i++){
                if(!exists[i])
                    return m + i;
            }
        }
};
