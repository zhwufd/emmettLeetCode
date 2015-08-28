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
        TreeNode* invertTree(TreeNode* root) {
            queue<TreeNode*> q;
            if(root != NULL) {
                q.push(root);
                while(!q.empty()) {
                    TreeNode* fr = q.front();
                    if(fr -> right != NULL || fr -> left != NULL) {
                        TreeNode* tmp = fr -> right;
                        fr -> right = fr -> left;
                        fr -> left = tmp;
                        if(fr -> right != NULL)
                            q.push(fr -> right);
                        if(fr -> left != NULL)
                            q.push(fr -> left);
                    }
                    q.pop();
                }
            }
            return root;
        }
};
