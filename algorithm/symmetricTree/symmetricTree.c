/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
 bool isSym(struct TreeNode* root1, struct TreeNode* root2){
    if(root1 == NULL && root2 == NULL)
        return true;
    else if(root1 != NULL && root2 != NULL){
        if(root1 -> val != root2 -> val)
            return false;
        if(!isSym(root1 -> right, root2 -> left))
            return false;
        if(!isSym(root1 -> left, root2 -> right))
            return false;
        return true;
    }
    else
        return false;
}
bool isSymmetric(struct TreeNode* root) {
    if(root != NULL)
        return isSym(root -> left, root -> right);
    else
        return true;
}
