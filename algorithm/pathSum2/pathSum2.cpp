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
    public:
    int c; 
    vector<int> v;
    int target;
    vector<vector<int>> vv;
    vector<vector<int>> pathSum(TreeNode* root,int sum) {
        c = 0;
        target = sum;
        traversal(root);
        return vv;
    }
    void traversal(TreeNode* root){
        if(root != NULL){
            c += root -> val;
            v.push_back(root -> val);
            if(root -> left != NULL){
                traversal(root -> left);
            }
            if(root -> right != NULL){
                traversal(root -> right);
            }
            if(root -> left == NULL && root -> right == NULL){ 
                if(c == target){
                    vv.push_back(v);
                }
            }
            c -= root -> val;
            v.erase(v.begin() + (v.size() - 1));
        }
    }
};
