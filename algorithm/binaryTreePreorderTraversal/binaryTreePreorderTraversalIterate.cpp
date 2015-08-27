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
            stack<TreeNode*> s;
            s.push(root);
            vector<int> outvec;
            while(!s.empty()) {
                TreeNode* t = s.top();
                outvec.push_back(t -> val);
                s.pop();
                if(t -> right != NULL) {
                    s.push(t -> right);
                }
                if(t -> left != NULL) {
                    s.push(t -> left);
                }
            }
            return outvec;
        }
        else {
            return vector<int>(0);
        }
    }
};
