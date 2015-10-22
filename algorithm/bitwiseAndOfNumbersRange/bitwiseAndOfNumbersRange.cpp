class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int wm = wid(m);
            int wn = wid(n);
            if(wn > wm)
                return 0;
            else{
                int i = wn - 2;
                for(; i >= 0; i--){
                    int tm = m &(1<<i);
                    int tn = n &(1<<i);
                    if(tm != tn)
                        break;
                }
                return m - m %(1<<(i+1));
            }
        }
        int wid(int m){
            int i = 0;
            while( m > 0){
                i++;
                m /= 2;
            }
            return i;
        }
};
