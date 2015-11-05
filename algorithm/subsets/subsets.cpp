#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void subsets(vector<int>& nums, int k, vector<vector<int> >& ss){
    if(k == 0){
        vector<int> tmp(1,nums[0]);
        ss.push_back(tmp);
        vector<int> tmp1;
        ss.push_back(tmp1);
    }
    else{
        subsets(nums, k - 1, ss);
        int sz = ss.size();
        for(int i = 0; i < sz; i++){
            vector<int> tmp2 = ss[i];
            tmp2.push_back(nums[k]);
            ss.push_back(tmp2);
        }
    }
}

vector<vector<int> > subsets(vector<int>& nums){
    sort(nums.begin(),nums.end());
    vector<vector<int> > ss;
    int n = nums.size();
    ss.reserve(pow(2,n));
    subsets(nums, n - 1, ss);
    return ss;
}

void printVecVec(vector<vector<int> >& ss){
    for(int i = 0; i < ss.size(); i++){
        cout << "[";
        for(int j = 0; j < ss[i].size(); j++){
            cout << ss[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

int main(){
    int a[] = {1, 4, 2, 3};
    vector<int> nums(a, a+4);
    vector<vector<int> > ss = subsets(nums);
    printVecVec(ss);
    return 0;
}
