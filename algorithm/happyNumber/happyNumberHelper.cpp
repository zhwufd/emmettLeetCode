#include <iostream>
#include <vector>
using namespace std;
vector<bool> happy(101,false);

int main(){
    for(int i = 1; i < 101; i++){
        int n = i;
        int itr = 1;
        while(n != 1 && itr <= 1000){
            int nn = 0;
            while(n > 0){
                int r = n%10;
                nn += (r*r);
                n /= 10;
            }
            n = nn;
            itr++;
        }
        if(n == 1)
            happy[i] = true;
    }
    for(int i = 1; i <= 100; i++){
        if(happy[i])
            cout << i <<" ";
    }
    return 0;
}
