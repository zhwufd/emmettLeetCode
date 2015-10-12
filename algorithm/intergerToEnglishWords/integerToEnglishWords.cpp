#include <iostream>
#include <vector>
#include <string>
using namespace std;
string threeToWord(int a,int b, int c, int k){
    string onetostr[10] = {"", "One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    string twotostr[10] = { "","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",\
        "Seventeen", "Eighteen","Nineteen"};
    string threetostr[10] = {"","Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    string tmp[5] = {"","Thousand","Million","Billion","Trillion"};
    k = (k + 1)/3;
    k--;
    string s1 = "";
    if(a > 0){
        s1 += " ";
        s1 += onetostr[a];
        s1 += " Hundred";
    }
    if(c == 0){
        if(b > 0){
            s1 += " ";
            s1 += threetostr[b];
        }
    }
    else if(b == 1){
        s1 += " ";
        s1 += twotostr[c];
    }
    else{
        if(b > 1){
            s1 += " ";
            s1 += threetostr[b];
        }
        s1 += " ";
        s1 += onetostr[c];
    }
    if(a >0 || b>0||c>0){
        if( k > 0){
            s1 += " ";
            s1 += tmp[k];
        }
    }
    return s1;
}
string numberToWords(int num){
    vector<int> en(13,0);
    string s = "";
    if(num == 0)
        return s + "Zero";
    int i = 0;
    while(num > 0){
        en[i] = num%10;
        num = num/10;
        i++;
    }
    int j =2;
    for(; j <i; j+=3){
       s = threeToWord(en[j],en[j-1],en[j-2], j) + s;
    }
    if(j -i < 2){
        s = threeToWord(en[j],en[j-1],en[j-2],j) + s;
    }
    return s.substr(1);
}
int main(){
    cout << numberToWords(10000)<<endl;
    cout << numberToWords(100000)<<endl;
    cout << numberToWords(12345)<<endl;
    cout << numberToWords(1234567)<<endl;
    return 0;
}
