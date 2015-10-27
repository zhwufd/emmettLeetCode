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
        vector<vector<int>> levelOrderBottom(TreeNode* root) {
            vector<vector<int>> vv;
            if(root != NULL){
                bool flag = true;
                bool even = true;
                vector<TreeNode*> t(1, root);
                vector<TreeNode*> tt;
                vector<int> v;
                while(flag){
                    v.clear();
                    if(even){
                        tt.clear();
                        for(int i = 0; i < t.size(); i++){
                            v.push_back(t[i] -> val);
                            TreeNode* lt = t[i] -> left;
                            TreeNode* rt = t[i] -> right;
                            if(lt != NULL)
                                tt.push_back(lt);
                            if(rt != NULL)
                                tt.push_back(rt);
                        }
                        if(tt.empty())
                            flag = false;
                    }
                    else{
                        t.clear();
                        for(int i = 0; i < tt.size(); i++){
                            v.push_back(tt[i] -> val);
                            TreeNode* lt = tt[i] -> left;
                            TreeNode* rt = tt[i] -> right;
                            if(lt != NULL)
                                t.push_back(lt);
                            if(rt != NULL)
                                t.push_back(rt);
                        }
                        if(t.empty())
                            flag = false;
                    }
                    even = !even;
                    vv.push_back(v);
                }
            }
            int i = 0;
            int j = vv.size() - 1;
            while(i < j){
                vector<int> tmp = vv[i];
                vv[i] = vv[j];
                vv[j] = tmp;
                i++;
                j--;
            }
            return vv;
        }
};
