#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0;
    for(int j = 0; j < nums.size();j++){
        if(nums[j] != 0){
            if(j != i){
                int tmp = nums[j];
                nums[j] = nums[i];
                nums[i] = tmp;
            }
            i++;
        }
    }
}
int main() {
    int a[] = {1, 0 ,1,2,3,0,0,0,4};
    vector<int> n(a, a+9);
    moveZeroes(n);
    for(int i = 0; i < n.size(); i++){
        cout << n[i]<<endl;
    }
    return 0;
}
