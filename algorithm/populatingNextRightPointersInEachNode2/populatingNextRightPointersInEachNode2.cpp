#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root) {
    if(root != NULL){
        bool flag = true;
        vector<TreeLinkNode*> v1(1,root);
        vector<TreeLinkNode*> v2;
        bool even = true;
        while(flag){
            if(even){
                v2.clear();
                int n1 = v1.size();
                for(int i = 0; i <= (n1 - 2); i++)
                    v1[i] -> next = v1[i+1];
                for(int i = 0; i < n1; i++){
                    TreeLinkNode* t = v1[i];
                    if(t -> left != NULL)
                        v2.push_back(t -> left);
                    if(t -> right != NULL)
                        v2.push_back(t -> right);
                }
                if(v2.empty())
                    flag = false;
            }
            else{
                v1.clear();
                int n2 = v2.size();
                for(int i = 0; i <= (n2 - 2); i++)
                    v2[i] -> next = v2[i+1];
                for(int i = 0; i < n2; i++){
                    TreeLinkNode* t = v2[i];
                    if(t -> left != NULL)
                        v1.push_back(t -> left);
                    if(t -> right != NULL)
                        v1.push_back(t -> right);
                }
                if(v1.empty())
                    flag = false;
            }
            even = !even;
        }
    }
}
int main(){
    TreeLinkNode rt(0);
    TreeLinkNode* root = &rt;
    connect(root);
    return 0;
}
