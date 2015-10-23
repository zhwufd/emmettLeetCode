class Solution {
    public:
        bool isHappy(int n) {
            if(n <= 0)
                return false;
            vector<bool> happy(101,false);
            int a[20] = {1,7,10,13,19,23,28,31,32,44,49,68,70,79,82,86,91,94,97,100};
            for(int i = 0; i < 20; i++){
                happy[a[i]] = true;
            }
            while( n > 100){
                int nn = 0;
                while(n > 0){
                    int r = n%10;
                    nn += (r*r);
                    n /= 10;
                }
                n = nn;
            }
            return happy[n];
        }
};
