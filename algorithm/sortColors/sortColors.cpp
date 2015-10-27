class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int n = nums.size();
            int i = 0;
            int j = 0;
            for(; i < n; i++){
                if(nums[i] < 1){
                    if(i != j){
                        int tmp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = tmp;
                    }
                    j++;
                }
            }
            int k = j;
            for(i = j; i < n; i++){
                if(nums[i] == 1){
                    if(i != k){
                        int tmp = nums[i];
                        nums[i] = nums[k];
                        nums[k] = tmp;
                    }
                    k++;
                }
            }
        }
};
