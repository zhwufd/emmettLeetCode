#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int hIndex(vector<int>& citations){
    int sz = citations.size();
    if(sz > 0){
        sort(citations.begin(),citations.end());
        int j = sz - 1; 
        while( j >= 0 ){
            if( citations[j] <= sz){
                int bidx = j;
                while( bidx < sz && citations[bidx] == citations[j])
                    bidx++;
                int sidx = j;
                while( sidx >= 0 && citations[sidx] == citations[j])
                    sidx--;
                int bcnt = sz - bidx;
                int scnt = sidx + 1;
                if(bidx < sz){
                    if( bcnt < citations[bidx] && bcnt > citations[bidx-1])
                        return bcnt;
                }
                if( sz - sidx > citations[j] && sz - bidx <= citations[j])
                    return citations[j];
                j = sidx;
            }
            else
                j--;
        }
        if(j == -1){
            if(sz < citations[0])
                return sz;
        }
    }
    return 0;
}

int main(){
    vector<int> a1(2,1);
    a1[1] = 2;
    cout << hIndex(a1)<<endl;
    //int v1[] = {3, 0, 6, 1, 5};
    //vector<int> a2(v1,v1+5);
    //cout << hIndex(a2)<<endl;
    return 0;
}

