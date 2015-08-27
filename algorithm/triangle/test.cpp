#include "triangle.cpp"
#include <vector>
#include <iostream>
using namespace std;
int main(){
    Solution s;
    vector< vector<int> > data(2, vector<int>(1,1));
    data[1][0] = 2;
    data[1].push_back(3);
    cout<<data[1].size()<<endl;
    int res = s.minimumTotal(data);
    cout<<res<<endl;
    system("pause");
    return 0;
}
