#include <vector>
#include <iostream>
using namespace std;

vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> out;
    int m = matrix.size();
    if( m > 0){
        int n = matrix[0].size();
        if(n > 0){
            int maxcnt = m * n;
            int cnt = 0;
            int flag = 0;
            int rmin = 0;
            int rmax = m - 1;
            int cmin = 0;
            int cmax = n - 1;
            int i = 0, j = 0;
            while(cnt < maxcnt){
                while( i >= rmin && i <= rmax && j >= cmin && j <= cmax){
                    out.push_back(matrix[i][j]);
                    ++cnt;
                    switch(flag){
                        case 0:
                            j++;
                            break;
                        case 1:
                            i++;
                            break;
                        case 2:
                            j--;
                            break;
                        case 3:
                            i--;
                    }
                }
                switch(flag){
                    case 0:
                        ++rmin;
                        i = rmin;
                        j = cmax;
                        break;
                    case 1:
                        --cmax;
                        j = cmax;
                        i = rmax;
                        break;
                    case 2:
                        --rmax;
                        i = rmax;
                        j = cmin;
                        break;
                    case 3:
                        ++cmin;
                        j = cmin;
                        i = rmin;
                }
                ++flag;
                flag = flag % 4;
            }
        }
    }
    return out;
}

int main(){
    vector<vector<int> > matrix;
    int a[4] = {1,2,3,4};
    vector<int> aa(a,a+4);
    int b[4] = {10,5,6,11};
    vector<int> bb(b,b+4);
    int c[4] = {7,8,9,12};
    vector<int> cc(c,c+4);
    matrix.push_back(aa);
    matrix.push_back(bb);
    matrix.push_back(cc);
    cout << " the matrix is: "<<endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            cout<< matrix[i][j] << " ";
        }
        cout << endl;
    }
    cout <<" the spiral order is: "<<endl;
    vector<int> v = spiralOrder(matrix);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
