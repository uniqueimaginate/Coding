#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int label;
    TreeNode* parent;
    vector<TreeNode*> children;
};

struct BinaryTreeNode{
    int label;
    TreeNode* parent;
    TreeNode* left, right;
}

void printLables(TreeNode* root){
    cout << root->label << endl;
    for(int i=0; i< root->children.size(); ++i){
        printLabels(root->children[i]);
    }
}

int height(TreeNode *root){
    int h = 0;
    for(int i=0; i < root->children.size(); ++i){
        h = max(h, 1 + height(root->children[i]));
    }
    return h;
}

int main(){
    return 0;
}
