class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> um;
        for(int i = 0; i < nums.size(); i++){
            if(um.count(nums[i]) == 0)
                um.insert( pair<int, bool>(nums[i],true));
            else
                return true;
        }
        return false;
    }
};
