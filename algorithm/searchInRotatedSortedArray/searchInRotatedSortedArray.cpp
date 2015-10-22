#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)
        return 0;
    int start = 0;
    int end = n - 1;
    if(nums[start] < nums[end])
        return start;
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
            return j + 1;
    }
    return start;
}

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int midx = findMin(nums);
    int start = 0;
    int end = n - 1;
    if(midx != 0){
        if(nums[0] > target)
            start = midx;
        else if(nums[0] < target)
            end = midx - 1;
        else
            return 0;
    }
    int mid = start + (end - start)/2;
    while(end - start > 1){
        if(nums[mid] > target)
            end = mid - 1;
        else if(nums[mid] == target)
            return mid;
        else
            start = mid + 1;
        mid = start + (end - start)/2;
    }
    for(int j = start; j <= end; j++){
        if(nums[j] == target)
            return j;
    }
    return -1;
}
int main(){
    int a[6] = {1,2,3,4,5,6};
    vector<int> nums(a,a+6);
    int target = 4;
    cout << search(nums,target) << endl;
    return 0;
}
