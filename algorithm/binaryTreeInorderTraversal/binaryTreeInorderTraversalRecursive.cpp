#include <cstdlib>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode * left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

vector<int> inorderTraversal(TreeNode* root){
    vector<int> v;
    inorderTraversal(root, v);
    return v;
}

void inorderTraversal(TreeNode* root, vector<int>& v){
    if(root != NULL){
        if(root -> left != NULL){
            inorderTraversal(root -> left, v);
        }
        v.push_back(root -> val);
        if(root -> right != NULL){
            inorderTraversal(root ->right, v);
        }
    }
}

int main(){
    TreeNode root(1);
    TreeNode left(2);
    TreeNode leftleft(3);
    TreeNode leftright(4);
    TreeNode right(5);
    TreeNode rightleft(6);
    root.left = &left;
    root.right = &right;
    left.left = &leftleft;
    left.right = &leftright;
    right.left = &rightleft;
    vector<int> v = inorderTraversal(&root);
    for(int i = 0; i < v.size(); i++){
        cout << v[i]<< "-";
    }
    cout << endl;
    return 0;
}
