#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens){
    stack<int> stk;
    for(int i = 0; i < tokens.size(); i++){
        string s = tokens[i];
        if(s == "+" || s == "-"||s=="*"||s=="/"){
            int oprd1 = stk.top();
            stk.pop();
            int oprd2 = stk.top();
            stk.pop();
            int res = 0;
            if(s == "+"){
                res = oprd1 + oprd2;
            }
            else if(s == "-"){
                res = oprd2 - oprd1;
            }
            else if(s == "*"){ 
                res = oprd2 * oprd1;
            }
            else if(s == "/"){
                res = oprd2 / oprd1;
            }
            stk.push(res);
        }
        else{
            stk.push(stoi(s));
        }
    }
    if(!stk.empty())
        return stk.top();
    else
        return 0;
}

int main(){
    string r1[5] = {"2","1","+","3","*"};
    vector<string> vs1(r1,r1+5);
    string r2[5] = {"4","13","5","/","+"};
    vector<string> vs2(r2,r2+5);
    cout << evalRPN(vs1)<<endl<< evalRPN(vs2)<<endl;
    return 0;
}
