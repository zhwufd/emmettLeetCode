#include <iostream>
#include <vector>
using namespace std;

int maxSubArray(vector<int>& nums){
    int n = nums.size();
    if(n <= 0)
        return 0;
    else{
        int maxsum = nums[0];
        int csum = nums[0];
        for(int i = 1; i < n; i++){
            int tmp = csum + nums[i];
            csum = (tmp > nums[i]) ? tmp : nums[i];
            if(csum > maxsum)
                maxsum = csum;
        }
        return maxsum;
    }
}

int main(){
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> aa(a, a+9);
    cout << maxSubArray(aa) << endl;
    return 0;
}
