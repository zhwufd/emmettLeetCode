#include <iostream>
using namespace std;

int uniquePaths(int m, int n){
    int cnt = 0;
    if( m > 0 && n > 0){
        int min = (m > n) ? n : m;
        int max = (m > n) ? m : n;
        double k = (double)min -1;
        double all = (double)m + n - 2;
        double out = 1.0;
        for(int i = 1; i < min; i++){
            out *=( all/k);
            all -= 1;
            k -= 1;
        }
        cnt = (int)out;
        if(out - cnt >0.5)
            cnt++;
    }
    return cnt;
}

int main(){
    cout << 3 << " " << 7 << " " << uniquePaths(3,7) << endl;
    //cout << 100 << " " << 100 << " " << uniquePaths(100,100) << endl;
    return 0;
}
