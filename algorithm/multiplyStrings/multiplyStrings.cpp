#include <iostream>
#include <string>
using namespace std;

string multiply(string num1, string num2) {
    int n1 = num1.length();
    int n2 = num2.length();
    int inc = 0;
    string num3 = "";
    for(int i = 0; i <=(n1+n2-2); i++){
        int tmp = 0;
        for(int j =0; j<=i; j++){
            if( j < n1 && (i - j) < n2)
                tmp += (num1[n1-1-j]-'0')*(num2[n2 -1-i+j]-'0');
        }
        tmp += inc;
        int m = tmp%10;
        inc = tmp/10;
        char c = '0'+m;
        num3 = c + num3;
    }
    string num4 = "";
    if(inc != 0)
        num4 = to_string(inc);
    string num5 = num4 + num3;
    int i = 0;
    for(; i < num5.length(); i++){
        if(num5[i] != '0')
            break;
    }
    if(i != num5.length())
        return num5.substr(i);
    else
        return "0";
}

int main(){
    string num1 = "9233";
    string num2 = "0";
    cout << multiply(num1, num2) << endl;
    return 0;
}
