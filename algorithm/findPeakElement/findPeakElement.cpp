#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums){
    int n = nums.size();
    if(n < 1)
        return -1;
    else if(n == 1)
        return 0;
    else if(n == 2)
        return (nums[0] > nums[1]) ? 0 : 1;
    else{
        int start  = 0;
        int end = n - 1;
        if(nums[start] > nums[start + 1])
            return start;
        if(nums[end] > nums[end - 1])
            return end;
        int mid = start + (end - start)/2;
        while(end - start >= 2){
            if(nums[mid] > nums[mid-1])
                if(nums[mid] > nums[mid + 1])
                    return mid;
                else
                    start = mid;
            else
                end = mid;
            mid = start + (end - start)/2;
        }
        return -1;
    }
}

int main(){
    int a[5] = { 1,2,3,5,2};
    vector<int> nums(a,a+5);
    cout << findPeakElement(nums) << endl;
    return 0;
}
