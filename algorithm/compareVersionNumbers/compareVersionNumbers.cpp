#include <iostream>
using namespace std;

int compareVersion(string version1, string version2) {
    int i1 = 0,i2 = 0;
    int n1 = version1.length();
    int n2 = version2.length();
    int j1 = 0,j2 = 0;
    while( i1 < n1 || i2 < n2 ){
        j1 = i1;
        while(j1 < n1){
            if(version1[j1] != '.')
                j1++;
            else
                break;
        }
        int v1 = 0;
        if(j1 - 1 >= i1)
            v1 = stoi(version1.substr(i1, j1-i1));
        i1 = j1 + 1;
        j2 = i2;
        while(j2 < n2){
            if(version2[j2] != '.')
                j2++;
            else
                break;
        }
        int v2 = 0;
        if(j2 - 1 >= i2)
            v2 = stoi(version2.substr(i2, j2-i2));
        i2 = j2 + 1;
        if( v1 > v2)
            return 1;
        else if ( v1 < v2)
            return -1;
    }
    return 0;
}

int main(){
    string version1 = "1.1.2";
    string version2 = "1.1.10";
    cout << compareVersion(version1,version2)<<endl;
    version1 = "1.1";
    version2 = "1.1.0";
    cout << compareVersion(version1,version2)<<endl;
    version1 = "1.10";
    version2 = "1.10.11";
    cout << compareVersion(version1,version2)<<endl;
    return 0;
}
