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
    string c = ""; 
    int sum = 0;
    public:
    int sumNumbers(TreeNode* root) {
        travesal(root);
        return sum;
    }
    void travesal(TreeNode* root){
        if(root != NULL){
            c += ('0' + root -> val);
            if(root -> left != NULL){
                travesal(root -> left);
            }
            if(root -> right != NULL){
                travesal(root -> right);
            }
            if(root -> left == NULL && root -> right == NULL){
                sum += stoi(c);
            }
            c.erase(c.end() - 1) ;
        }
    }
};
