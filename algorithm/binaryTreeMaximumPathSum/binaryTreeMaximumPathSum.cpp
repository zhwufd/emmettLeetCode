#include <cstdlib>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:
        int leftmax0;
        int leftmax1;
        int rightmax0;
        int rightmax1;
        int rootmax0;
        int rootmax1;
        int maxPathSum(TreeNode* root) {
            if(root != NULL){
                vector<int> rootmax = maxSum(root);
                return rootmax[1];
            }
            else
                return INT_MIN;
        }
        vector<int> maxSum(TreeNode* root){
            vector<int> rootmax(2,root -> val);
            vector<int> leftmax(2,0);
            vector<int> rightmax(2,0);
            if(root -> left != NULL){
                leftmax = maxSum(root -> left);
                if(leftmax0 > 0)
                    rootmax0 += leftmax0;
                if(leftmax[1] > rootmax[1])
                    rootmax[1] = leftmax[1];
                if((leftmax[0] + root -> val) > rootmax[1])
                    rootmax[1] = leftmax[0] + root -> val;
            }
            if(root -> right != NULL){
                rightmax = maxSum(root -> right);
                if((root -> val + rightmax[0]) > rootmax[0])
                    rootmax[0] = root -> val + rightmax[0];
                if((rightmax[0] + root -> val) > rootmax[1])
                    rootmax[1] = rightmax[0] + root -> val;
                if(rightmax[1] > rootmax[1])
                    rootmax[1] = rightmax[1];
            }
            if(root -> right != NULL && root -> left != NULL){
                if((leftmax[0] + root -> val + rightmax[0]) > rootmax[1])
                    rootmax[1] = leftmax[0]+rightmax[0]+root -> val;
            }
            return rootmax;
        }
};
