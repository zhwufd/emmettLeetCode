/**
 ** Definition for a binary tree node.
 ** struct TreeNode {
 **     int val;
 **     TreeNode *left;
 **     TreeNode *right;
 **     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 ** };
 **/
struct NodeDep {
    TreeNode* node;
    int depth;
    NodeDep(TreeNode* a, int b){
        node = a;
        depth = b;
    }
};

class Solution {
    public:
        int minDepth(TreeNode* root) {
            if(root == NULL) {
                return 0;
            }
            else {
                stack<NodeDep> s;
                NodeDep v(root,1);
                s.push(v);
                int mindep = 1;
                bool leafflag = false;
                while(!s.empty()) {
                    NodeDep t = s.top();
                    s.pop();
                    if(t.node -> left != NULL) {
                        NodeDep w(t.node -> left,t.depth + 1);
                        s.push(w);
                    }
                    if(t.node -> right != NULL) {
                        NodeDep x(t.node -> right,t.depth + 1);
                        s.push(x);
                    }
                    if(t.node -> left == NULL && t.node -> right == NULL) {
                        if(!leafflag){
                            mindep = t.depth;
                            leafflag = true;
                        }
                        else {
                            mindep = (mindep < t.depth) ? mindep : t.depth;
                        }
                    }
                }
                return mindep;
            }
        }
};
