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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root != NULL){
            if(root -> left == NULL && root -> right == NULL){
                return vector<int>(1, root -> val);
            }
            else {
                vector<int> v;
                if(root -> left != NULL) {
                    vector<int> leftv = postorderTraversal(root -> left);
                    v.insert(v.end(),leftv.begin(),leftv.end());
                }
                if(root -> right != NULL) {
                    vector<int> rightv = postorderTraversal(root -> right);
                    v.insert(v.end(),rightv.begin(),rightv.end());
                }
                v.push_back(root -> val);
                return v;
            }
        }
        else {
            return vector<int>(0);
        }
        
    }
};
