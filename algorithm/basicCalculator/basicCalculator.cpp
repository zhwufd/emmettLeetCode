#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct numop {
    char c;
    int t;
    numop(int tt): c('0'),t(tt){}
    numop(char cc): c(cc),t(0){}
};

int calculate(string s){
    vector<numop> stk;
    int n = s.length();
    stk.reserve(n);
    int i = 0;
    while(i < n){
        //push stack
        if(s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-'){
            stk.push_back(numop(s[i]));
            i++;
        }
        else if(s[i] >= '0' && s[i] <= '9'){
            int j = i + 1;
            while(j < n && s[j] >='0' && s[j] <= '9') j++;
            int op2 = stoi(s.substr(i, j-i));
            stk.push_back(numop(op2));
            i = j;
        }
        else
            i++;
        // calculate
        while(!stk.empty()){
            int sz = stk.size();
            numop en = stk[sz - 1];
            char ec = en.c;
            int et = en.t;
            if(ec == '+' || ec == '-' || ec == '(')
                break;
            else if(ec == ')' && sz > 2){
                stk.pop_back();
                numop tmp = stk.back();
                stk.pop_back();
                stk.pop_back();
                stk.push_back(tmp);
            }
            else if(ec == '0'){
                if(sz == 1)
                    break;
                else{
                    numop en1 = stk[sz - 2];
                    if(en1.c == '(')
                        break;
                    else if(en1.c == '+' || en1.c == '-'){
                        int op1 = stk[sz-3].t;
                        int op2 = et;
                        int res = (en1.c == '+')? (op1 + op2) :(op1-op2);
                        stk.pop_back();
                        stk.pop_back();
                        stk.pop_back();
                        stk.push_back(numop(res));
                    }
                    else
                        break;
                }
            }
            else
                break;
        }
    }
    if(!stk.empty())
        return stk.back().t;
    else
        return -1;
}

int main(){
    vector<string> test;
    test.push_back("1+1");
    test.push_back("2-1 + 2 ");
    test.push_back("(1+(4 + 5+2)-3)+(6+8)");
    for(int i = 0; i < test.size(); i++){
        cout << test[i]<< " " << calculate(test[i])<<endl;
    }
    return 0;
}
