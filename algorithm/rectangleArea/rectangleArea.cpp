#include <vector>

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        vector<int> cx = commflag(A, C, E, G);
        int commx = cx[0];
        int flagx = cx[1];
        vector<int> cy = commflag(B, D, F, H);
        int commy = cy[0];
        int flagy = cy[1];
        int comm_area = 0;
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        if(flagx == -1 || flagy == -1) {
            comm_area = 0;
        }
        else if(flagx > 0 && flagy > 0) {
            if(flagx == flagy) {
                return (area1 > area2) ? area1 : area2;
            }
            else
                comm_area = commx * commy;
        }
        else {
            comm_area = commx * commy;
        }
        return area1 + area2 - comm_area;
    }
    vector<int> commflag(int A, int C, int E, int G) {
        int commx;
        int flagx;
        if(E< A) {
            if(G < A) {
                commx = 0;
                flagx = -1;
            }
            else if (G < C) {
                commx = G - A;
                flagx = 0;
            }
            else {
                commx = C - A;
                flagx = 2;
            }
        }
        else if(E < C) {
            if(G < C) {
                commx = G - E;
                flagx = 1;
            }
            else {
                commx = C - E;
                flagx = 0;
            }
        }
        else {
            commx = 0;
            flagx = -1;
        }
        vector<int> res(2,0);
        res[0] = commx;
        res[1] = flagx;
        return res;
    }
};
