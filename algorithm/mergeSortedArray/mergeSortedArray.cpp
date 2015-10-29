#include <vector>
#include <iostream>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> tmp(m+n,0);
    int i= 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            tmp[k] = nums1[i];
            i++;
        }
        else{
            tmp[k] = nums2[j];
            j++;
        }
        k++;
    }
    if(i == m){
        for(; j <n; j++){
            tmp[k] = nums2[j];
            k++;
        }
    }
    if(j == n){
        for(; i < m; i++){
            tmp[k] = nums1[i];
            k++;
        }
    }
    for(i = 0; i< (m+n); i++){
        nums1[i] = tmp[i];
    }
}

void printVec(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int s1[6] = {1,2,3,0,0,0};
    vector<int> nums1(s1,s1+6);
    cout << " nums1: "<<endl;
    printVec(nums1);
    int s2[3] = {2,5,6};
    vector<int> nums2(s2,s2+3);
    cout <<" nums2: " <<endl;
    printVec(nums2);
    merge(nums1, 3, nums2, 3);
    printVec(nums1);
    return 0;
}
