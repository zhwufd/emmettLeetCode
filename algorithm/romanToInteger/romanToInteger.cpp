#include <iostream>
#include <string>
using namespace std;

int romanToInt(char c1, char c2, int &i){
    int t = 0;
    switch(c1){
        case 'I':
            if(c2 == 'V'){
                t += 4;
                i++;
            }
            else if(c2 == 'X'){
                t += 9;
                i++;
            }
            else
                ++t;
            break;
        case 'X':
            if(c2 == 'L'){
                t += 40;
                i++;
            }
            else if(c2 == 'C'){
                t += 90;
                i++;
            }
            else
                t += 10;
            break;
        case 'C':
            if(c2 == 'D'){
                t += 400;
                i++;
            }
            else if(c2 == 'M'){
                t += 900;
                i++;
            }
            else
                t += 100;
            break;
        case 'V':
            t += 5;
            break;
        case 'L':
            t += 50;
            break;
        case 'D':
            t += 500;
            break;
        case 'M':
            t += 1000;
            break;
    }
    i++;
    return t;
}
int romanToInt(string s){
    int t = 0;
    int i = 0;
    int n = s.length();
    while(i < n - 1){
        t += romanToInt(s[i], s[i+1], i);
    }
    if(i < n)
        t += romanToInt(s[i],'0', i);
    return t;
}

int main(){
    string s = "";
    while(cin >> s){
        cout << romanToInt(s) << endl;
    }
    return 0;
}
