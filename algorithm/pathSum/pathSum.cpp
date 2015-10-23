#include <cstdlib>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int c; 
    int target;
    public:
    int hasPathSum(TreeNode* root,int sum) {
        c = 0;
        target = sum;
        return travesal(root);
    }
    bool travesal(TreeNode* root){
        if(root != NULL){
            c += root -> val;
            if(root -> left != NULL){
                if(travesal(root -> left))
                    return true;
            }
            if(root -> right != NULL){
                if(travesal(root -> right))
                    return true;
            }
            if(root -> left == NULL && root -> right == NULL){ 
                if(c == target)
                    return true;
            }
            c -= root -> val;
            return false;
        }
        return false;
    }
};
