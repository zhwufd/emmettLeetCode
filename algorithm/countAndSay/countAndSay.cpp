#include <string>
#include <iostream>
using namespace std;

string transfer(string& s1){
    string s2 = "";
    int n = s1.length();
    if(n > 0){
        int i = 0;
        while(i < n){
            int j = i;
            while(j < n-1 && s1[j] == s1[j+1])
                j++;
            int cnt = j - i + 1;
            s2 += to_string(cnt);
            s2 += s1[i];
            i = j + 1;
        }
    }
    return s2;
}

string countAndSay(int n){
    string s1 = "1";
    string s2 = "1";
    bool flag = true;
    for(int i = 2; i <= n; i++){
        if(flag){
            s2 = transfer(s1);
        }
        else{
            s1 = transfer(s2);
        }
        flag = !flag;
    }
    return flag? s1 : s2;
}

int main(){
    for(int i = 1; i <= 30; i++)
        cout << countAndSay(i) << endl;
    return 0;
}
