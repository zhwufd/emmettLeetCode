class Solution{
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root){
            vector<vector<TreeNode*>> vv;
            vector<vector<int>> out;
            if(root != NULL){
                vector<TreeNode*> t(1, root);
                vector<int> s(1, root -> val);
                vv.push_back(t);
                out.push_back(s);
                bool flag = true;
                bool even = true;
                while(flag){
                    vector<TreeNode*> prev = vv[vv.size() - 1];
                    vector<TreeNode*> cur;
                    vector<int> curout;
                    int n = prev.size();
                    for(auto i = prev.rbegin(); i != prev.rend(); i++){
                        if(even){
                            if((*i)->right != NULL){
                                cur.push_back((*i)->right);
                                curout.push_back((*i)->right -> val);
                            }
                            if((*i)->left != NULL){
                                cur.push_back((*i)->left);
                                curout.push_back((*i)->left -> val);
                            }
                        }
                        else{
                            if((*i)->left != NULL){
                                cur.push_back((*i)->left);
                                curout.push_back((*i)->left -> val);
                            }
                            if((*i)->right != NULL){
                                cur.push_back((*i)->right);
                                curout.push_back((*i)->right -> val);
                            }
                        }
                    }
                    even = !even;
                    if(cur.empty())
                        flag = false;
                    else{
                        vv.push_back(cur);
                        out.push_back(curout);
                    }
                }
            }
            return out;
        }
};

