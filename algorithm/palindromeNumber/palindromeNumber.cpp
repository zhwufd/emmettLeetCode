#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0){
        return false;
    }
    int d = 1;
    while(x/d > 9)
        d *= 10;
    while(d > 1){
        if(x/d == x%10){
            x -= d*(x%10);
            x /= 10;
            d /= 100;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    for(int i = 0; i < 300; i++)
        cout << i << " " << isPalindrome(i) <<endl;
    return 0;
}
