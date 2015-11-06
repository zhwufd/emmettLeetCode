#include <iostream>
#include <string>
using namespace std;

string longestPalindrome(string s){
    int maxlen = 1;
    int maxstart = 0;
    int maxend = 0;
    int n = s.length();
    for(int i = 1; i < n; i++){
        int j = i - 1;
        int k = i + 1;
        while(j >= 0 && k < n && s[j] == s[k]){
            j--;
            k++;
        }
        int start = j + 1;
        int end = k - 1;
        int len = end - start + 1;
        if(len > maxlen){
            maxlen = len;
            maxstart = start;
            maxend = end;
        }
    }
    for(int i = 0; i < n - 1; i++){
        int j = i;
        int k = i + 1;
        while(j >= 0 && k < n && s[j] == s[k]){
            j--;
            k++;
        }
        int start = j + 1;
        int end = k - 1;
        int len = end - start + 1;
        if(len > maxlen){
            maxlen = len;
            maxstart = start;
            maxend = end;
        }
    }
    return s.substr(maxstart, maxlen);
}

int main(){
    string s = "fjkakalgabccbaruqoghohg";
    cout << s << endl << longestPalindrome(s) << endl;
    return 0;
}
