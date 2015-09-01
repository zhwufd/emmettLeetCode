#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map<int,int> um;
            for(auto i = 0; i < nums.size(); i++) {
                if(um.count(nums[i]) == 1){
                    um[nums[i]] += 1;
                }
                else
                    um.insert(pair<int,int>(nums[i],1));
            }
            for(auto it = um.begin(); it != um.end(); ++it ){
                if(it -> second != 2){
                    return it -> first;
                }
            }
            return 0;
        }
};
