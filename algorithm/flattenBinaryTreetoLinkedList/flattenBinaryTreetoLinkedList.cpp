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
        void flatten(TreeNode* root) {
            if(root != NULL)
                flat(root);
        }
        TreeNode* flat(TreeNode* root) {
            TreeNode* left = root -> left;
            TreeNode* right = root -> right;
            TreeNode* leftend = NULL;
            if(left != NULL) {
                leftend = flat(left);
                root -> left = NULL;
                root -> right = left;
            }
            TreeNode* rightend = NULL;
            if(right != NULL) {
                rightend = flat(right);
                if(leftend != NULL) {
                    leftend -> right = right;
                }
            }
            if(left == NULL) {
                if(right == NULL)
                    return root;
                else
                    return rightend;
            }
            else{
                if(right == NULL)
                    return leftend;
                else
                    return rightend;
            }
        }
};
