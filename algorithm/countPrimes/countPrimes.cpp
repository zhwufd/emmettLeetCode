#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int countPrimes(int n){
    if(n <= 2)
        return 0;
    else{
        vector<bool> isp(n+1,true);
        for(int i = 2; i <=sqrt(n); i++){
            if(isp[i]){
                int j = i;
                while(i*j <= n){
                    isp[i*j] = false;
                    j++;
                }
            }
        }
        int cnt = 0;
        for(int i = 2; i <n; i++){
           if(isp[i])
               cnt++;
        }
        return cnt;
    }
}
int main(){
    int a[] = {4,7,10,15,200000};
    for(int i = 0; i < 5; i++){
        cout << a[i] <<" " << countPrimes(a[i]) <<endl;
    }
    return 0;
}
