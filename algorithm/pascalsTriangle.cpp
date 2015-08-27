class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > s(0);
        if(numRows > 0) {
            for(int i = 1; i <= numRows; i++) {
                if(i == 1){
                    s.push_back(vector<int>(1,1));
                }
                else {
                    vector<int> t(i,1);
                    for(int j = 1; j <= i -2; j++){
                        t[j] = s[i-1][j-1] + s[i-1][j];
                    }
                    s.push_back(t);
                }
            }
        }
        return s;
    }
};
