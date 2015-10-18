class Solution {
    public:
        bool isValid(string s) {
            stack<char> stk;
            for(int i = 0; i < s.length(); i++){
                if(s[i] == '(' || s[i] == '[')
                    stk.push(s[i]);
                else if(s[i] == ')' || s[i] == ']'){
                    if(stk.empty())
                        return false;
                    else{
                        char t = stk.top();
                        if(s[i] == ')'){
                            if(t != '(')
                                return false;
                        }
                        else if(s[i] == ']'){
                            if(t != '[')
                                return false;
                        }
                        stk.pop();
                    }
                }
            }
            if(stk.empty())
                return true;
            else
                return false;
        }
};
