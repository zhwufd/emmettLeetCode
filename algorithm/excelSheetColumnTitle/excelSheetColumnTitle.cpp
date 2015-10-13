#include <iostream>
#include <string>
using namespace std;

string convertToTitle(int n){
    string s = "";
    while( n > 0 ) {
        --n;
        char c = 'A' + n%26;
        s = c + s;
        n /= 26;
    }
    return s;
}

int main(){
    for(int i = 1; i < 100; i++){
        cout << convertToTitle(i) << endl;
    }
    return 0;
}
