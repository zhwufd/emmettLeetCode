#include <iostream>
#include <vector>
using namespace std;

int findDuplicate(vector<int>& nums){
    int n = nums.size() - 1;
    if(n < 1)
        return -1;
    int i = 1;
    int j = n;
    int mid = (i + j)/2;
    while(j > i){
        int cnt1 = 0;
        int cnt2 = 0;
        for(int k = 0; k <= n; k++){
            if(nums[k] < mid)
                cnt1++;
            else if(nums[k] == mid)
                cnt2++;
        }
        if(cnt2 > 1)
            return mid;
        if(cnt1 >= mid)
            j = mid - 1;
        else
            i = mid + 1;
        mid = (i + j)/2;
    }
    return i;
}

int main(){
    int a[6] = {1,2,3,2,4,5};
    vector<int> aa(a, a+6);
    cout << findDuplicate(aa) << endl;
    return 0;
}
