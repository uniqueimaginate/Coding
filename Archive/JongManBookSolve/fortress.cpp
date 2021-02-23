#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode{
    vector<TreeNode*> children;
};

int longest;

int height(TreeNode *root){
    vector<int> heights;

    for(int i=0; i < root->children.size(); ++i){
        heights.push_back(height(root->children[i]));
    }

    if(height.empty()) return 0;
    sort(heights.begin(), heights.end());

    if(heights.size() >=2){
        longest = max(longest, 2 + heights[heights.size()-2] + heights[heights.size()-1]);
    }

    return heights.back() + 1;
}

int solve(TreeNode *root){
    longest = 0;
    int h = height(root);
    return max(longest, h);
}

// Continue;

int main(){

}