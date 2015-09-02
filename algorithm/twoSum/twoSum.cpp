#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int,int> um;
            for(int i = 0; i < nums.size(); i++) {
                um.insert(pair<int,int>(nums[i], i+1) );
            }
            for(int i = 0; i < nums.size(); i++) {
                if(um.count(target - nums[i]) > 0) {
                    int a1 = i + 1;
                    int a2 = um[target - nums[i]];
                    if(a1 == a2)
                        continue;
                    vector<int> outvec;
                    if(a1 > a2) {
                        outvec.push_back(a2);
                        outvec.push_back(a1);
                    }
                    else {
                        outvec.push_back(a1);
                        outvec.push_back(a2);
                    }
                    return outvec;
                }
            }
        }
};
