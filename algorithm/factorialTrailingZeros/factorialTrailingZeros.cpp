#include <iostream>
#include <climits>
using namespace std;

int trailingZeroes(int n) {
    int cnt5 = 0;
    int d = 5;
    while(n/d > 0){
        cnt5 += (n/d);
        if(INT_MAX/5 >= d)
            d *= 5;
        else
            break;
    }
    return cnt5;
}

int main(){
    int n = 1808548329;
    cout << trailingZeroes(n) << endl;
    return 0;
}
