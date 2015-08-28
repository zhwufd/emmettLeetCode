class Solution {
    public:
        int numTrees(int n) {
            vector<int> num(n+1,1);
            for(int i = 2; i <= n; i++) {
                int cnt = 0;
                for(int j = 0; j < i; j++) {
                    cnt += num[j] * num[i - 1 - j];
                }
                num[i] = cnt;
            }
            return num[n];
        }
};
