class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int n = nums.size();
		map<int,int> nmap;
		for(int i = 0; i < n; i++) {
			if( nmap.count(nums[i]) == 0) {
				nmap[nums[i]] = 1;
			}
			else
				nmap[nums[i]] += 1;
			if(nmap[nums[i]] > n/2)
				return nums[i];
		}
	}
};
