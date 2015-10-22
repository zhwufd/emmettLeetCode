class Solution {
public:
    string addBinary(string a, string b) {
        int na = a.length();
        int nb = b.length();
        int nmax =(na > nb)? na : nb;
        string out = "";
        int inc = 0;
        int ca = 0;
        int cb = 0;
        for(int i = 0; i < nmax; i++){
            int ia = na - 1 - i;
            int ib = nb - 1 - i;
            if(ia >= 0)
                ca = a[ia] - '0';
            else
                ca = 0;
            if(ib >= 0)
                cb = b[ib] - '0';
            else
                cb = 0;
            int t = ca + cb + inc;
            char c = '0' + (t%2);
            inc = t/2;
            out = c + out;
        }
        if(inc > 0)
            out = '1' + out;
        return out;
    }
};
