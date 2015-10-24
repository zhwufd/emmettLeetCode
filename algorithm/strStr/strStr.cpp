class Solution {
    public:
        int strStr(string haystack, string needle) {
            int i = 0;
            int hlen = haystack.length();
            int nlen = needle.length();
            for(int i = 0; i <= hlen - nlen; i++){
                if(haystack.substr(i,nlen) == needle)
                    return i;
            }
            return -1;
        }
};
