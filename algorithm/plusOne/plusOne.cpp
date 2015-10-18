class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            if(digits.size() > 0){
                for(int i = digits.size() - 1; i >= 0; i--){
                    digits[i]++;
                    if(digits[i] < 10)
                        break;
                    else if(i != 0)
                        digits[i] = 0;
                }
                if(digits[0] == 10){
                    digits[0] = 0;
                    vector<int> out(1,1);
                    out.insert(out.end(),digits.begin(),digits.end());
                    return out;
                }
            }
            return digits;
        }
};
