#include <iostream>
#include <string>
#include <vector>
using namespace std;

void partition(string &s, int i, vector<string> &t, vector<vector<string> > &d){
    int n = s.length();
    if(i == n){
        d.push_back(t);
    }
    else{
        for(int j = i; j < n; j++){
            //check palindrome
            int p = i;
            int q = j;
            while(p < q && s[p] == s[q]){
                p++;
                q--;
            }
            if(p >= q){
                t.push_back(s.substr(i, j -i +1));
                partition(s, j+1, t, d);
                t.pop_back();
            }
        }
    }
}

vector<vector<string> > partition(string s){
    vector<vector<string> > d;
    vector<string> t;
    int n = s.length();
    if(n == 0)
        return d;
    partition(s, 0, t, d);
    return d;
}

void printVecVec(vector<vector<string> > vv){
    for(int i = 0; i < vv.size(); i++){
        for(int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
}

int main(){
    string s = "aabcbec";
    vector<vector<string> > vv = partition(s);
    printVecVec(vv);
    return 0;
}
