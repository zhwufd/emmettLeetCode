#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

ostream& operator <<(ostream &o, const Interval& a){
    return o<<"["<<a.start<<","<<a.end<<"]";
}

void printVecInt(vector<Interval>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

ostream& operator<< (ostream &o, const vector<Interval>& v){
    for(int i = 0; i < v.size(); i++){
        o << v[i] << " ";
    }
    return o<<endl;
}

vector<Interval> parseVec(vector<int>& v){
    vector<Interval> vint;
    int n = v.size();
    if(n%2)
        n--;
    for(int i = 0; i < n/2; i++){
        Interval s(v[2*i], v[2*i+1]);
        vint.push_back(s);
    }
    return vint;
}
class comp{
    public:
        bool operator()(Interval a, Interval b){
            if(a.start < b.start)
                return true;
            else if( a.start == b.start)
                return (a.end < b.end)? true: false;
            else
                return false;
        }
};

vector<Interval> merge(vector<Interval>& intervals){
    comp mycomp;
    sort(intervals.begin(), intervals.end(), mycomp);
    vector<Interval> vout;
    int i = 0; 
    int n = intervals.size();
    int imax = 0, imin = 0;
    int cmin = 0, cmax = 0;
    Interval s;
    while(i < n){
        if(i == 0){
            imax = intervals[i].end;
            imin = intervals[i].start;
        }
        else{
            cmin = intervals[i].start;
            cmax = intervals[i].end;
            if(cmin <= imax){
                if(cmax > imax)
                    imax = cmax;
            }
            else{
                s.start = imin;
                s.end = imax;
                vout.push_back(s);
                imin = cmin;
                imax = cmax;
            }
        }
        i++;
    }
    if(n > 0){
        s.start = imin;
        s.end = imax;
        vout.push_back(s);
    }
    return vout;
}

int main(){
    //int a[] = {74,78,61,63,46,50,51,54,50,50,60,64,39,42,25,27,91,95,14,16,85,85,5,7,45,46,45,49,66,66,73,73,25,26,25,26};
    //vector<int>  aa(a,a+36);
    //vector<Interval> vint = parseVec(aa);
    vector<Interval> vint;
    int is = 0, ie = 0;
    Interval s;
    ifstream ifs;
    ifs.open("1.in");
    while(ifs >> is >> ie){
       s.start = is;
       s.end = ie;
       vint.push_back(s);
    }
    ifs.close();
    cout << vint;
    vector<Interval> vout = merge(vint);
    cout << "merge intervals" << endl << vout;
    return 0;
}
