#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minimumTotal(vector< vector<int> >& triangle) {
        int n = triangle.size();
        if(n > 0) {
            vector<int> v0 = triangle[0];
            if(v0.size() > 0){
                vector<int> v1(0);
                int flag;
                for(int i = 1; i < n; i++){
                    flag = i%2;
                    if(flag == 1) {
                        cout<<triangle[i][0]<<" "<<triangle[i][1]<<endl;
                        cout<<triangle[i].size()<<endl;
                        v1 = update(v0, triangle[i]);
                    }
                    else {
                        v0 = update(v1, triangle[i]);
                    }
                }
                return (flag == 1) ? minnum(v1) : minnum(v0);
            }
        }
        return 0;
    }
    
    vector<int> update(vector<int> v0, vector<int> tr) {
        vector<int> v1(0);
        for(int j = 0; j < tr.size(); j++) { 
            if(j == 0){
                v1.push_back(v0[0] + tr[0]);
            }
            else if( j == tr.size() - 1) {
                v1.push_back(v0[j-1] + tr[j]);
            }
            else {
                int premin = ( v0[j-1] > v0[j] )? v0[j] : v0[j-1];
                v1.push_back(premin + tr[j]);
            }
        }
        return v1;
    }
    
    int minnum(vector<int> v) {
        if(v.size() > 0) {
            int m = v[0];
            for(int i = 1; i < v.size(); i++){
                if(m > v[i]) m = v[i];
            }
            return m;
        }
        else {
            return 0;
        }
    }
};
