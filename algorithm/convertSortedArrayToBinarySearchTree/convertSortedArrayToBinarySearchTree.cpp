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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = NULL;
        toBST(root, nums, 0, n-1);
        return root;
    }
    void toBST(TreeNode*& root, vector<int>& nums, int start, int end){
        if(start <= end){
            int mid = start + (end - start)/2;
            root = new TreeNode(nums[mid]);
            toBST(root -> left, nums, start, mid - 1);
            toBST(root -> right, nums, mid + 1, end);
        }
    }
};
