#include <iostream>
using namespace std;

int mySqrt(int x){
    if(x <= 0)
        return 0;
    else if(x == 1)
        return 1;
    else{
        int i = 1;
        int j = x-1;
        int mid = (i + j)/2;
        while(i <= j){
            if(mid > x/mid){
                j = mid - 1;
            }
            else if( (mid+1) >x/(mid+1)){
                return mid;
            }
            else{
                i = mid + 1;
            }
            mid = (i + j)/2;
        }
        return mid;
    }
}
int main(){
    cout << mySqrt(2147483647)<<endl;
    return 0;
}
