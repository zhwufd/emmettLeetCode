class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string,char> um1;
        unordered_map<char,string> um2;
        int start = -1;
        int end = -1;
        for(int i = 0; i < pattern.length(); i++){
            start = end + 1;
            char v = pattern[i];
            end = start;
            while(str[end] != ' ' && end < str.length())
                end++;
            string k = str.substr(start, end - start);
            if(um1.count(k) > 0){
                if(um1[k] != v){
                    return false;
                }
            }
            else if(um2.count(v) > 0){
                if(um2[v]!= k){
                    return false;
                }
            }
            else{
                um1.insert(pair<string,char>(k,v));
                um2.insert(pair<char,string>(v,k));
            }
            if(end == str.length() && i + 1 != pattern.length()){
                return false;
            }
        }
        if(end != str.length())
            return false;
        else
            return true;
    }
};
