#include <stddef.h>

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root == NULL)
                return NULL;
            TreeNode* itr = root;
            int itrv = itr -> val;
            int pv = p -> val;
            int qv = q -> val;
            while( ( (itrv - pv) > 0 &&  (itrv - qv) > 0) || ((itrv - pv) < 0 && (itrv -qv) < 0) ) {
                if(itr -> right != NULL) {
                    int rightv = itr -> right -> val;
                    if( ( (itrv - pv) > 0 && (itrv -rightv) < 0 ) || ((itrv - pv) <0 && (itrv -rightv) >0) ){
                        itr = itr -> left;
                    }
                    else{
                        itr = itr -> right;
                    }
                }
                else {
                    itr = itr -> left;
                }
                itrv = itr -> val;
            }
            return itr;
        }
};
