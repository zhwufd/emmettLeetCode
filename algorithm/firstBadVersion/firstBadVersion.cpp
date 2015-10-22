#include <iostream>
using namespace std;
// Forward declaration of isBadVersion API.
int fbv = 2147483647;
bool isBadVersion(int version){
    if(version >= fbv)
        return true;
    else
        return false;
}
int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    int mid = start + (end - start)/2;
    while(end - 1 > start ){
        if(isBadVersion(mid)){
            end = mid;
        }
        else
            start = mid + 1;
        mid = start + ( end - start )/2;
    }
    for(int j = start; j <= end; j++){
        if(isBadVersion(j))
            return j;
    }
    return 0;
}

int main(){
    int n = 2147483647;
    cout << firstBadVersion(n) << endl;
    return 0;
}
