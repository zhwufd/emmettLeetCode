#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> strToIp(string s, int i){
    if(i == 1){
        int n = s.length();
        if( n > 0 && n < 4){
            if(s[0] == '0' && s.length() > 1){
                vector<string> v(0);
                return v;
            }
            int d = stoi(s);
            if(d >= 0 && d <= 255){
                vector<string> v(1,s);
                return v;
            }
            else{
                vector<string> v(0);
                return v;
            }
        }
        else{
            vector<string> v(0);
            return v;
        }
    }
    else{
        vector<string> out;
        int n = s.length();
        if( n > 0 ) {
            string s1 = s.substr(0,1);
            int d = stoi(s1);
            if(d >= 0 && d <= 255){
                s1 += '.';
                vector<string> res = strToIp(s.substr(1), i-1);
                if(res.size() > 0){
                    for(int i = 0; i < res.size(); i++){
                        out.push_back(s1 + res[i]);
                    }
                }
            }
        }
        if( n > 1) {
            string s1 = s.substr(0,2);
            if(s1[0] != '0'){
                int d = stoi(s1);
                if(d >= 0 && d <= 255){
                    s1 += '.';
                    vector<string> res = strToIp(s.substr(2), i-1);
                    if(res.size() > 0){
                        for(int i = 0; i < res.size(); i++){
                            out.push_back(s1 + res[i]);
                        }
                    }
                }
            }
        }
        if( n > 2) {
            string s1 = s.substr(0,3);
            if(s1[0] != '0'){
                int d = stoi(s1);
                if(d >= 0 && d <= 255){
                    s1 += '.';
                    vector<string> res = strToIp(s.substr(3), i-1);
                    if(res.size() > 0){
                        for(int i = 0; i < res.size(); i++){
                            out.push_back(s1 + res[i]);
                        }
                    }
                }
            }
        }
        return out;
    }
}

vector<string> restoreIpAddresses(string s){
    return strToIp(s,4);
}

int main(){
    //string s = "0279245587303";
    string s = "10100219254";
    vector<string> out = restoreIpAddresses(s);
    for(int i = 0; i< out.size(); i++){
        cout << out[i] << endl;
    }
    return 0;
}
