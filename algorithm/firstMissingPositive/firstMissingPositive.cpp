#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i] <= n && nums[i] > 0 && nums[i] != (i+1)){
            if(nums[nums[i] - 1] != nums[i]){
                //swap(i, nums[i] - 1)
                int tmp = nums[i];
                nums[i] = nums[nums[i] - 1];
                nums[tmp - 1]= tmp;
            }
            else
                break;
        }
    }
    for(int i = 0; i < n; i++){
        if(nums[i] != (i+1)){
            return i+1;
        }
    }
    return n+1;
}

int main(){
    vector<int> a(1,1);
    cout << firstMissingPositive(a) <<endl;
    return 0;
}

