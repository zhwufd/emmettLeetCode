#include "minimumPathSum.cpp"

int main() {
	Solution s;
	vector< vector<int> > grid(2,vector<int>(2,0));
	grid[0][0] = 1;
	grid[0][1] = 2;
	grid[1][0] = 1;
	grid[1][1] = 1;
	int m = s.minPathSum(grid);
	return 0;
}
