#include <vector>
#include <iostream>
using namespace std;

int findKthLargest(vector<int>& nums, int k, int start, int end){
    if(start <= end && (end - start + 1) >= k){
        if((end - start + 1) == 1)
            return nums[start];
        else if((end - start + 1) == 2){
            if(k == 1)
                return (nums[start] >= nums[end])?nums[start]:nums[end];
            else
                return (nums[start] < nums[end])?nums[start]:nums[end];
        }
        else{
            int sp = nums[end];
            int i = start;
            int j = start;
            while( j < end){
                if(nums[j] < sp){
                    if(j != i){
                        int tmp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = tmp;
                    }
                    i++;
                }
                j++;
            }
            int tmp = nums[i];
            nums[i] = nums[end];
            nums[end] = tmp;
            if( (end - i + 1) > k){
                start = i + 1;
                return findKthLargest(nums, k, start, end);
            }
            else if( (end - i + 1) < k){
                k -= (end -i +1);
                end = i - 1;
                return findKthLargest(nums, k, start, end);
            }
            else
                return nums[i];
        }
    }
    return -1;
}

int findKthLargest(vector<int>& nums, int k){
    return findKthLargest(nums, k, 0, nums.size() - 1);
}

int main(){
    int a[] = {3,2,1,5,6,4};
    vector<int> nums(a,a+6);
    int k = 2;
    cout << findKthLargest(nums,k) << endl;
    k = 3;
    cout << findKthLargest(nums,k) << endl;
    return 0;
}
