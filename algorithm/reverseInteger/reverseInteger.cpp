#include <iostream>
#include <string>
#include <climits>
using namespace std;

int reverse(int x) {
    bool flag = false;
    if(x == 0)
        return 0;
    else if(x < 0){
        flag = true;
        if( x == INT_MIN)
            return 0;
        x = -x;
    }
    string s = to_string(x);
    int i = 0;
    int j = s.length() - 1;
    while(i < j){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++;
        j--;
    }
    i = 0;
    while(i < s.length() && s[i] == '0')
        i++;
    s = s.substr(i);
    string maxs = to_string(INT_MAX);
    if(s.length() == maxs.length()){
        for(int i = 0; i< s.length(); i++){
            if(s[i] > maxs[i])
                return 0;
            else if( s[i] < maxs[i])
                break;
        }
    }
    x = stoi(s);
    if(flag)
        x = -x;
    return x;
}

int main(){
    cout << reverse(-2147483648) <<endl;
    cout << reverse(100)<<endl;
    cout << reverse(12032)<<endl;
    return 0;
}
