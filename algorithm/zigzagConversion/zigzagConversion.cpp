class Solution {
    public:
        string convert(string s, int numRows) {
            if(numRows == 1)
                return s;
            bool isDown = false;
            int r = 0;
            vector<string> vs(numRows,"");
            for(int i = 0; i < s.length(); i++) {
                vs[r] += s[i];
                if(r == (numRows - 1) || r == 0) {
                    isDown = !isDown;
                }
                if(isDown)
                    ++r;
                else
                    --r;
            }
            string outstr;
            for(int i = 0; i < vs.size(); i++){
                outstr += vs[i];
            }
            return outstr;
        }
};
