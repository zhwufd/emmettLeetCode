#include <iostream>
#include "pathSum.cpp"
using namespace std;
int main(){
    TreeNode* root = new TreeNode(2);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(3);
    Solution s;
    int res = s.hasPathSum(root,5);
    cout << res << endl;
    res = s.hasPathSum(root,4);
    cout << res << endl;
    res = s.hasPathSum(root,1);
    cout << res << endl;
    return 0;
}
