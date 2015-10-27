/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root != NULL){
            TreeLinkNode* rl = root -> left;
            TreeLinkNode* rr = root -> right;
            while( rl != NULL && rr != NULL){
                rl -> next = rr;
                rl = rl -> right;
                rr = rr -> left;
            }
            rl = root -> left;
            rr = root -> right;
            if(rl != NULL)
                connect(rl);
            if(rr != NULL)
                connect(rr);
        }
    }
};
