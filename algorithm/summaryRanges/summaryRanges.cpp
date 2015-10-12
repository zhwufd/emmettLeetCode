#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<string> summaryRanges(vector<int>& nums) {
    int n = nums.size();
    vector<string> vs;
    if( n > 0 ) {
        int start = nums[0];
        int prev = start;
        for(int i =1; i < n; i++){
            if(nums[i] > prev + 1){
                string s = "";
                if(start == prev) {
                    s = to_string(start);
                }
                else{
                    s = to_string(start) + "->" + to_string(prev);
                }
                vs.push_back(s);
                start = nums[i];
                prev = nums[i];
            }
            else{
                prev = nums[i];
            }
        }
        if(start == prev) {
            vs.push_back(to_string(start));
        }
        else{
            string s = to_string(start) + "->" + to_string(prev);
            vs.push_back(s);
        }
    }
    return vs;
}

int main(){
    int a[] = {0,2,5,6,9,10};
    vector<int> nums(a,a+6);
    vector<string> s = summaryRanges(nums);
    for(int i = 0; i< s.size(); i++){
        cout << s[i]<<endl;
    }
    return 0;
}
