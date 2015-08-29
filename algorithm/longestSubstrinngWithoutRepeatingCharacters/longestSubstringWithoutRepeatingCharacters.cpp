class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxsublen = 0;
        map<char,int> sc;
        int i = 0;
        int start = 0;
        int sublen,end;
        while(i < s.length()){
            char c = s[i];
            if(sc.find(c) == sc.end())
                sc.insert(pair<char,int>(c,i));
            else {
                end = sc[c];
                sublen = i - start;
                maxsublen = (maxsublen < sublen) ? sublen : maxsublen;
                for(int j = start; j < end; j++){
                    sc.erase(s[j]);
                }
                sc[c] = i;
                start = end + 1;
            }
            ++i;
        }
        sublen = i - start;
        maxsublen = (maxsublen < sublen) ? sublen : maxsublen;
        return maxsublen;
    }
};
