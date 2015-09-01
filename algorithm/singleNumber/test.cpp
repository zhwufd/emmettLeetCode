#include "singleNumber.cpp"
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> nums = {1, 3, 3, 1, 0};
    Solution s;
    int t = s.singleNumber(nums);
    cout << t <<endl;
    return 0;
}
