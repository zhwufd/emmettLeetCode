#include "triangle.cpp"
#include <vector>
using namespace std;
int main(){
    Solution s;
    vector< vector<int> > data(2, vector<int>(1,1));
    data[1][0] = 2;
    data[1][1] = 3;
    int res = s.minimumTotal(data);
    return 0;
}
