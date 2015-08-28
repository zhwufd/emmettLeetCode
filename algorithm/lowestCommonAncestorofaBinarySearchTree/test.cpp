#include "lca.cpp"

int main() {
    TreeNode t1 = TreeNode(-57762);
    TreeNode* root = &t1;
    TreeNode t2 = TreeNode(-76299);
    root -> left = &t2;
    TreeNode t3 = TreeNode(-20080);
    root -> right = &t3;
    TreeNode t4 = TreeNode(-78708);
    root -> left ->left = &t4;
    TreeNode t5 = TreeNode(-70912);
    root -> left -> right = &t5;
    TreeNode t6 = TreeNode(-32641);
    root -> right -> left = &t6;
    TreeNode t7 = TreeNode(27427);
    root -> right -> right = &t7;
    Solution s;
    TreeNode* sol = s.lowestCommonAncestor(root, &t7, &t6);
    int v = sol -> val;
    return 0;
}
