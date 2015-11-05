#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    int n = nums.size();
    vector<int> leftProd(n,0);
    vector<int> rightProd(n,0);
    int p = 1;
    for(int i = 0; i < n-1; i++){
        p *= nums[i];
        leftProd[i] = p;
    }
    p = 1;
    for(int i = n - 1; i > 0; i--){
        p *= nums[i];
        rightProd[i] = p;
    }
    vector<int> pes(n,0);
    for(int i = 0; i < n; i++){
        if(i == 0){
            pes[i] = rightProd[1];
        }
        else if(i == (n-1)){
            pes[i] = leftProd[n-2];
        }
        else{
            pes[i] = leftProd[i-1] * rightProd[i+1];
        }
    }
    return pes;
}

ostream& operator<<(ostream& o, vector<int>& t){
    for(int i = 0; i < t.size(); i++){
        o << t[i] << " ";
    }
    return o<<endl;
}

int main(){
    int a[] = {1,2,3,4};
    vector<int> nums(a,a+4);
    cout << nums;
    vector<int> pes = productExceptSelf(nums);
    cout << pes;
    return 0;
}
