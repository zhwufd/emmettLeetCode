#include <string>
#include <iostream>
using namespace std;

bool isAlpha(char c) {
    if(c >= 'A' && c <= 'Z'){
        return true;
    }
    else if(c >= 'a' && c <= 'z')
        return true;
    else if(c >= '0' && c <= '9')
        return true;
    else
        return false;
}

char chalpha(char c){
    if(c >= 'A' && c <= 'Z')
        c += ('a' - 'A');
    return c;
}
bool isPalindrome(string s) {
    int i = 0;
    int j = s.length() - 1;
    while( i < j ){
        while(!isAlpha(s[i]) && i < s.length())
            i++;
        while(!isAlpha(s[j]) && j >=0 )
            j--;
        if(i <= j){
            if(chalpha(s[i]) != chalpha(s[j]))
                return false;
            else{
                i++;
                j--;
            }
        }
    }
    return true;
}

int main(){
    string s ="1a23";
    cout << isPalindrome(s) <<endl;
    return 0;
}
