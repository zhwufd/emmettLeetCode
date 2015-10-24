class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int j = nums.size() - 1;
        if(i > j)
            return 0;
        for(;;){
            while(nums[j] == val && j >= 0)
                j--;
            while(nums[i] != val && i < nums.size())
                i++;
            if(i < j){
                int tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
            }
            else
                break;
        }
        return j + 1;
    }
};
