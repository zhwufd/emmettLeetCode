#include <vector>
#include <iostream>
using namespace std;

int max3(int a, int b, int c){
    int d = (a > b)? a :b;
    d = (d > c)? d : c;
    return d;
}

int min3(int a, int b, int c){
    int d = (a < b)? a :b;
    d = (d < c)? d : c;
    return d;
}

int maxProduct(vector<int>& nums){
    int n = nums.size();
    if(n < 0)
        return 0;
    else{
        int maxp = nums[0];
        int premax = nums[0];
        int premin = nums[0];
        for(int i = 1; i < n; i++){
            int tmp1 = premax * nums[i];
            int tmp2 = premin * nums[i];
            premax = max3(tmp1, tmp2, nums[i]);
            premin = min3(tmp1, tmp2, nums[i]);
            if(premax > maxp)
                maxp = premax;
        }
        return maxp;
    }
}

int main(){
    int a[10] = {1,-2,3,-4,0,1,5,1,2,0};
    vector<int> aa(a, a+10);
    cout << maxProduct( aa) << endl;
    return 0;
}
