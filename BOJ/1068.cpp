#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode{
    int val;
    struct TreeNode* root;
    vector<TreeNode*> children;
}TreeNode;

int n, r, leefNum, root;

void find(TreeNode *root){
    if(root->children.size() == 0) {
        leefNum++;
        return;
    }
    for(int i=0; i<root->children.size(); ++i){
        find(root->children[i]);
    }
}

int main(){
    cin >> n;
    vector<TreeNode*> nodes;
    

    for(int i=0; i<n; ++i){
        TreeNode *temp = new TreeNode();
        temp->val = i;
        temp->root = NULL;
        nodes.push_back(temp);
    }

    for(int i=0; i<n; ++i){
        int temp;
        cin >> temp;
        if(temp == -1){root = i; continue;}
        nodes[i]->root = nodes[temp];
        nodes[temp]->children.push_back(nodes[i]);
    }

    cin >> r;
    if(r == root) {cout << leefNum << endl; return 0;}

    for(int i=0; i<nodes[r]->root->children.size(); ++i){
        if(nodes[r]->root->children[i]->val == r){
            nodes[r]->root->children.erase(nodes[r]->root->children.begin() + i);
        }
    }

    find(nodes[root]);
    cout << leefNum << endl;
}