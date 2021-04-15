#include <bits/stdc++.h>

using namespace std;

int c;

typedef struct TreeNode{
    char label;
    TreeNode *root;
    TreeNode *left, *right;
}TreeNode;

void preorder(TreeNode *root){
    cout << root->label;
    if(root->left){ 
        preorder(root->left);
    }
    if(root->right){
        preorder(root->right);
    }
    return;
}

void inorder(TreeNode *root){
    if(root->left){ 
        inorder(root->left);
    }
    cout << root->label;
    if(root->right){
        inorder(root->right);
    }
    return;
}

void postorder(TreeNode *root){
    if(root->left){ 
        postorder(root->left);
    }
    if(root->right){
        postorder(root->right);
    }
    cout << root->label;
    return;   
}

int main(){
    cin >> c;
    vector<TreeNode*> nodes;
    for(int i=0; i<c; i++){
        TreeNode *temp = new TreeNode();
        temp->label = 'A' + i;
        temp->root = NULL;
        temp->left = NULL;
        temp->right = NULL;
        nodes.push_back(temp);
    }

    while(c--){
        char root, left, right;
        scanf(" %c %c %c", &root, &left, &right);
        int rootPos = root - 'A';
        int leftPos, rightPos;
        if(left != '.') {
            leftPos = left - 'A';
            nodes[rootPos]->left = nodes[leftPos];
        }
        if(right != '.') {
            rightPos = right - 'A';
            nodes[rootPos]->right = nodes[rightPos];
        }
    }

    // for(int i=0; i<nodes.size(); ++i){
    //     cout << nodes[i]->label << " ";
    //     if(nodes[i]->left){
    //         cout << nodes[i]->left->label <<  " ";
    //     }
    //     else{
    //         cout << "." <<  " ";

    //     }
    //     if(nodes[i]->right){
    //         cout << nodes[i]->right->label << endl;
    //     }
    //     else{
    //         cout << "." <<  endl;

    //     }
    // }

    preorder(nodes[0]);
    cout << endl;
    inorder(nodes[0]);
    cout << endl;
    postorder(nodes[0]);
    cout << endl;

}