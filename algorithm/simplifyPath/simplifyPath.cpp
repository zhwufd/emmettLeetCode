#include <iostream>
#include <stack>
#include <string>
using namespace std;

string simplifyPath(string path){
    stack<string> s;
    int n = path.length();
    int i = 1;
    while(i < n){
        int j = i;
        while(j < n && path[j] != '/')
            j++;
        string t = path.substr(i, j - i);
        if(t != "." && t != ""){
            if(t == ".."){
                if(!s.empty())
                    s.pop();
            }
            else
                s.push(t);
        }
        i = j + 1;
    }
    string out = "";
    while(!s.empty()){
        string t = s.top();
        s.pop();
        out = ('/' + t) + out;
    }
    if(out == "")
        out = '/';
    return out;
}

int main(){
    string s1 = "/abd/...";
    string s2 = "/a/./b/../../../c/";
    cout << s1 << endl << simplifyPath(s1) << endl;
    cout << s2 << endl << simplifyPath(s2) << endl;
    return 0;
}
