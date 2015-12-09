class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
        int flag[10] = {};
        int bulls = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] == guess[i])
                bulls++;
            else
                flag[secret[i]-'0']++;
        }
        int cows = 0;
        for(int i = 0; i < n; i++){
            if(secret[i] != guess[i]){
                int k = guess[i] - '0';
                if(flag[k]){
                    cows++;
                    flag[k]--;
                }
            }
        }
        string s = to_string(bulls) + "A" + to_string(cows) + "B";
        return s;
    }
};
