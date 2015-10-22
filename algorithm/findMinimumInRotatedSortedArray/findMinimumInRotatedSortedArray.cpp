class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        int start = 0;
        int end = n - 1;
        if(nums[start] < nums[end])
            return nums[start];
        int mid = start + (end - start)/2;
        while(end - start > 1){
            if(nums[mid] > nums[start])
                start = mid;
            else if(nums[mid] < nums[end])
                end = mid;
            mid = start + (end - start)/2;
        }
        for(int j = start; j < end; j++){
            if(nums[j+1] < nums[j])
                return nums[j+1];
        }
        return nums[start];
    }
};
