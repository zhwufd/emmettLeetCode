#include <iostream>
#include <vector>
using namespace std;

void update(vector<int>& v1, int i, vector<int>& v2){
    v2[0] = 1;
    for(int j = 0; j < i; j++)
        v2[j+1] = v1[j] + v1[j+1];
    v2[i+1] = 1;
}

vector<int> getRow(int rowIndex){
    vector<int> v1(rowIndex + 1, 0);
    vector<int> v2(rowIndex + 1, 0);
    v1[0] = 1;
    bool even = true;
    int i = 0;
    while(i < rowIndex){
        if(even){
            update(v1, i, v2);
        }
        else
            update(v2, i, v1);
        i++;
        even = !even;
    }
    return even?v1:v2;
}

void printVec(vector<int>& v){
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout<<endl;
}

int main(){
    for(int i = 0; i < 10; i++){
        cout << i << endl;
        vector<int> v = getRow(i);
        printVec(v);
    }
    return 0;
}
