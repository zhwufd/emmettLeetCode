class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if( s.length() == t.length() ) {
			if( s.length() == 0 )
				return true;
			else {
				vector<int> ss = hashToVec(s);
				vector<int> tt = hashToVec(t);
				for(int i = 0; i< ss.size(); i++) {
					if( ss[i] != tt[i])
						return false;
				}
				return true;
			}
		}
		else
			return false;
	}
	vector<int> hashToVec(string s) {
		vector<int> ss;
		map<char,int> charmap;
		int cnt = 0;
		for(int i = 0; i < s.length(); i++) {
			if(charmap.count(s[i]) == 0) {
				charmap[s[i]] = cnt;
			    ++cnt;
			}
		    ss.push_back(charmap[s[i]]);
		}
	    return ss;
	}	
};
