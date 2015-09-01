class Solution {
    public:
        int titleToNumber(string s) {
            int n = s.length();
            int colnum = 0;
            if(n > 0){
                for(int i = 0; i < n; i++) {
                    char c = s[i];
                    colnum += pow(26, n - 1 - i) * (c - 'A' + 1);
                }
            }
            return colnum;
        }
};
