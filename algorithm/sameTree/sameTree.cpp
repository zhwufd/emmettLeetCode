i/**
  * Definition for a binary tree node.
  * struct TreeNode {
  *    int val;
  *    TreeNode *left;
  *    TreeNode *right;
  *    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  *};
  **/
class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            if(p == NULL) {
                if(q == NULL)
                    return true;
                else
                    return false;
            }
            else if(q == NULL)
                return false;
            else {
                int pv = p -> val;
                int qv = q -> val;
                bool flag = (pv == qv);
                if(flag) {
                    bool flagleft = isSameTree(p -> left, q -> left);
                    if(flagleft) {
                        bool flagright = isSameTree(p -> right, q -> right);
                        return flagright;
                    }
                    else {
                        return false;
                    }
                }
                else
                    return false;
            }
        }
};
