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
        vector<int> rightSideView(TreeNode* root) {
            vector<int> v;
            if(root != NULL){
                bool even = true;
                bool flag = true;
                vector<TreeNode*> t(1,root);
                vector<TreeNode*> tt;
                while(flag){
                    if(even){
                        v.push_back(t[0] -> val);
                        tt.clear();
                        for(int i = 0; i < t.size(); i++){
                            if(t[i] -> right != NULL)
                                tt.push_back(t[i] -> right);
                            if(t[i] -> left != NULL)
                                tt.push_back(t[i] -> left); 
                        }
                        if(tt.empty())
                            flag = false;
                    }
                    else{
                        v.push_back(tt[0] -> val);
                        t.clear();
                        for(int i = 0; i < tt.size(); i++){
                            if(tt[i] -> right != NULL)
                                t.push_back(tt[i] -> right);
                            if(tt[i] -> left != NULL)
                                t.push_back(tt[i] -> left);
                        }
                        if(t.empty())
                            flag = false;
                    }
                    even = !even;
                }
            }
            return v;
        }
};
