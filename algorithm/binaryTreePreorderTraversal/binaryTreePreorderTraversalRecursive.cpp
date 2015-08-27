/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root != NULL) {
            if(root -> left == NULL && root -> right == NULL) {
                return vector<int>(1,root -> val);
            }
            else {
                vector<int> v(1,root -> val);
                if( root -> left != NULL) {
                    vector<int> leftv = preorderTraversal(root -> left);
                    v.insert(v.end(),leftv.begin(),leftv.end());
                }
                if( root -> right != NULL) {
                    vector<int> rightv = preorderTraversal(root -> right);
                    v.insert(v.end(),rightv.begin(),rightv.end());
                }
                return v;
            }
        }
        else {
            return vector<int>(0);
        }
    }
};
