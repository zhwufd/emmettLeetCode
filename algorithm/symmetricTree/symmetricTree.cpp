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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        queue<TreeNode*> lefttree;
        lefttree.push(root -> left);
        queue<TreeNode*> righttree;
        righttree.push(root -> right);
        while((!lefttree.empty())&&(!righttree.empty())){
            TreeNode* lnode = lefttree.front();
            TreeNode* rnode = righttree.front();
            lefttree.pop();
            righttree.pop();
            if((lnode == NULL) != (rnode == NULL))
                return false;
            else if(lnode != NULL && rnode != NULL){
                if(lnode -> val != rnode -> val)
                    return false;
                lefttree.push(lnode -> left);
                lefttree.push(lnode -> right);
                righttree.push(rnode -> right);
                righttree.push(rnode -> left);
            }
        }
        if(lefttree.empty() == righttree.empty())
            return true;
        else
            return false;
    }
};
