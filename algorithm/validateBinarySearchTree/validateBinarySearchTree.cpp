/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if(root != NULL) {
                bool flag = isMedian(root);
                if(flag) {
                    bool flagleft = true;
                    if(root -> left != NULL)
                        flagleft = isValidBST(root -> left);
                    if(flagleft) {
                        bool flagright = true;
                        if(root -> right != NULL)
                            flagright = isValidBST(root -> right);
                        return flagright;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            else
                return true;
        }
        bool isMedian(TreeNode* root) {
            int midv = root -> val;
            if(root -> left != NULL) {
                TreeNode* itr = root -> left;
                while(itr -> right != NULL) {
                    itr = itr -> right;
                }
                int leftmax = itr -> val;
                if(leftmax >= midv)
                    return false;
            }
            if(root -> right != NULL) {
                TreeNode* itr = root -> right;
                while(itr -> left != NULL) {
                    itr = itr -> left;
                }
                int rightmin = itr -> val;
                if(rightmin <= midv)
                    return false;
            }
            return true;
        }
};
