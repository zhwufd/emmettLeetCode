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
    if(root != NULL){
        stack<TreeNode*> st;
        TreeNode* itr = root;
        while(itr != NULL){
            st.push(itr);
            itr = itr -> left;
        }
        TreeNode* cur = NULL;
        while(!st.empty()){
            cur = st.top();
            v.push_back(cur -> val);
            st.pop();
            itr = cur -> right;
            while(itr != NULL){
                st.push(itr);
                itr = itr -> left;
            }
        }
    }
    return v;
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
