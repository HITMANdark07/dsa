#include<bits/stdc++.h>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    int leftMax = maxDepth(node->left);
    int rightMax = maxDepth(node->right);

    return 1 +max(leftMax, rightMax);
}

int heightCheck(TreeNode *node){
    if(node==NULL){
        return 0;
    }
    int lMax = heightCheck(node->left);
    if(lMax==-1) return -1;
    int rMax = heightCheck(node->right);
    if(rMax==-1) return -1;
    if(abs(lMax-rMax)>1) return -1;

    return 1+max(lMax,rMax);
}
bool isBalanced(TreeNode *node){
    return heightCheck(node)!=-1;
}


int main(){
    TreeNode *node = new TreeNode(3);
    node->left = new TreeNode(9);
    node->right = new TreeNode(20);
    node->right->left = new TreeNode(15);
    node->right->right = new TreeNode(7);
    int d = maxDepth(node);
    cout<<d<<endl;
    bool c = isBalanced(node);
    if(c>0) cout<<"True"<<endl;
    else cout<<"False"<<endl;

}