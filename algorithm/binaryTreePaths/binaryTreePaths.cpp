#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void treeTravesal(TreeNode* root, string& s, vector<string>& vs){
    if(root != NULL){
        int len = s.length();
        string c = "->";
        c += to_string(root ->val);
        s += c;
        if(root -> left != NULL){
            treeTravesal(root -> left, s, vs);
        }
        if(root -> right != NULL){
            treeTravesal(root -> right, s, vs);
        }
        if(root -> left == NULL && root -> right == NULL){
            vs.push_back(s.substr(2));
        }
        s = s.substr(0,len);
    }
}

vector<string> binaryTreePaths(TreeNode* root){
    vector<string> vs;
    string s = "";
    treeTravesal(root, s, vs);
    return vs;
}

int main(){
    TreeNode root(1);
    TreeNode left(2);
    TreeNode leftright(5);
    TreeNode right(3);
    root.left = &left;
    root.right = &right;
    left.right = &leftright;
    vector<string> vs = binaryTreePaths(&root);
    for(int i = 0; i < vs.size(); i++){
        cout << vs[i] << endl;
    }
    return 0;
}
