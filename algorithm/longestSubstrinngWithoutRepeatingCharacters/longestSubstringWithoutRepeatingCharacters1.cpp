class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxsublen = 0;
        bool exists[256] = {false};
        int i = 0;
        int j = 0;
        while(j < n) {
            char c = s[j];
            if(!exists[c])
                exists[c] = true;
            else {
                maxsublen = max(maxsublen,j - i);
                while(s[i] != s[j]){
                   exists[s[i]] = false;
                   ++i;
                }
                ++i;
            }
            ++j;
        }
        maxsublen = max(maxsublen, j - i);
        return maxsublen;
    }
};
