#include <iostream>
#include "sumRootToLeafNumbers.cpp"
using namespace std;
int main(){
    TreeNode* root = new TreeNode(2);
    root -> left = new TreeNode(1);
    root -> right = new TreeNode(3);
    Solution s;
    int res = s.sumNumbers(root);
    cout << res << endl;
    return 0;
}
