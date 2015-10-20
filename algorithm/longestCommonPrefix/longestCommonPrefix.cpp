class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string lcp = "";
            if(strs.size() == 1)
                return strs[0];
            else if(strs.size() > 1){
                int minln = strs[0].length();
                for(int i = 1; i < strs.size(); i++){
                    if(minln > strs[i].length())
                        minln = strs[i].length();
                }
                for(int i = 0; i < minln; i++){
                    char t = strs[0][i];
                    bool flag = true;
                    for(int j = 1; j < strs.size(); j++){
                        if(strs[j][i] != t){
                            flag = false;
                            break;
                        }
                    }
                    if(flag)
                        lcp += t;
                    else
                        break;
                }
            }
            return lcp;
        }
};
