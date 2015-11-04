#include <string>
#include <iostream>
#include <vector>
using namespace std;

string m[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> letterCombinations(string digits){
    vector<string> tmp;
    int n = digits.length();
    if(n > 0){
        string sb = digits.substr(0, n-1);
        vector<string> pre = letterCombinations(sb);
        int k = digits[n-1] - '0';
        string a = m[k];
        if(a.length() > 0){
            for(int i = 0; i < a.length(); i++){
                string c = "";
                c += a[i];
                if(pre.size() > 0){
                    for(int j = 0; j < pre.size(); j++){
                        tmp.push_back(pre[j] + c);
                    }
                }
                else
                    tmp.push_back(c);
            }
        }
        else
            return pre;
    }
    return tmp;
}

void printVec(vector<string> a){
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << endl;
}

int main(){
    string dig = "23";
    vector<string> t = letterCombinations(dig);
    printVec(t);
    dig = "0";
    t = letterCombinations(dig);
    printVec(t);
    return 0;
}
