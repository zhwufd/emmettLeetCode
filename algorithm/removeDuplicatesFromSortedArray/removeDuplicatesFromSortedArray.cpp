class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            if(nums.size() <= 1)
                return nums.size();
            int i = 1;
            int j = 1;
            while(i < nums.size() && nums[i] == nums[i-1])
                i++;
            while(i < nums.size()){
                int k = i+1;
                while(k < nums.size() && nums[k]== nums[k-1])
                    k++;
                if(i!=j){
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                }
                j++;
                i = k;
            }
            return j;
        }
};
