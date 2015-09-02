#include "twoSum.cpp"
#include <vector>
using namespace std;

int main() {
    int a[] = { 1, 3, 2, 9};
    vector<int> b(a, a+ sizeof(a)/sizeof(int));
    int target = 10;
    Solution s;
    vector<int> outvec = s.twoSum(b, target);
    return 0;
}
