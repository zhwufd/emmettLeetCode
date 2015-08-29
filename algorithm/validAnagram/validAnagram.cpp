class Solution {
    public:
        bool isAnagram(string s, string t) {
            vector<int> sa = stat(s);
            vector<int> ta = stat(t);
            for(int i = 0; i < 26; i++){
                if(sa[i] != ta[i])
                    return false;
            }
            return true;
        }
        vector<int> stat(string s) {
            vector<int> outvec(26,0);
            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                ++outvec[c - 'a'];
            }
            return outvec;
        }
};
