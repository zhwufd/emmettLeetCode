#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector< vector<int> >& grid) {
		int m = grid.size();
		if(m > 0) {
			int n = grid[0].size();
			if( n > 0 ) {
				for(int j = 0;j < m;j++) {
					for(int i = 0;i < n;i++) {
						int tmp;
						if( i == 0 ) {
							if(j == 0) {
								tmp = 0;
							}
							else {
								tmp = grid[j-1][i];
							}
						}
						else {
							if(j == 0) {
								tmp = grid[j][i-1];
							}
							else {
								tmp = (grid[j-1][i] < grid[j][i-1]) ? grid[j-1][i] : grid[j][i-1];
							}
						}
					    grid[j][i] = tmp + grid[j][i];	
					}
				}
				return grid[m-1][n-1];
			}
		}
		return 0;
	}
};
