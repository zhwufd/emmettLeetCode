#include <string>
#include <iostream>
using namespace std;

string s1[10] = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
string s2[10] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
string s3[10] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
string intToRoman(int num){
    string out = "";
    int a1 = num%10;
    out = s1[a1] + out;
    num /= 10;
    if(num > 0){
        a1 = num%10;
        out = s2[a1] + out;
        num /= 10;
        if(num > 0){
            a1 = num%10;
            out = s3[a1] + out;
            num /= 10;
            string s4 = "";
            for(int i = 0; i < num; i++){
                s4 += "M";
            }
            out = s4 + out;
        }
    }
    return out;
}

int main(){
    for(int i = 1; i <= 1000; i++){
        cout << i << " " << intToRoman(i) << endl;
    }
    return 0;
}
