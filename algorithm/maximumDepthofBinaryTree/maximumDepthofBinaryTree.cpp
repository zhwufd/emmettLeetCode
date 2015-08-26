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
        int maxDepth(TreeNode* root) {
            if(root == NULL) {
                return 0;
            }
            else {
                stack<NodeDep> s;
                NodeDep v(root,1);
                s.push(v);
                int maxdep = 0;
                while(!s.empty()) {
                    NodeDep t = s.top();
                    maxdep = (maxdep < t.depth) ? t.depth : maxdep;
                    s.pop();
                    if(t.node -> left != NULL) {
                        NodeDep w(t.node -> left,t.depth + 1);
                        s.push(w);
                    }
                    if(t.node -> right != NULL) {
                        NodeDep x(t.node -> right,t.depth + 1);
                        s.push(x);
                    }
                }
                return maxdep;
            }
        }
};
