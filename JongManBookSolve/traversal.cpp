#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N;

vector<int> slice(const vector<int>& v, int a, int b){
    return vector<int>(v.begin() + a, v.begin() + b);
}

void printPostOrders(const vector<int>& preorder, const vector<int>& innerorder){
    const int N = preorder.size();
    if(preorder.empty()) return;
    const int root = preorder[0];
    
    const int L = find(innerorder.begin(), innerorder.end(), root) - innerorder.begin();
    const int R = N - L - 1;

    printPostOrders(slice(preorder, 1, L+1), slice(innerorder, 0, L));
    printPostOrders(slice(preorder, L+1, N), slice(innerorder, L+1, N));

    cout << root << " ";
}


int main(){
    cin >> C;
    while(C--){
        cin >> N;
        vector<int> preorder;
        vector<int> innerorder;
        for(int i=0; i<N; ++i){
            int temp;
            cin >> temp;
            preorder.push_back(temp);
        }
        for(int i=0; i<N; ++i){
            int temp;
            cin >> temp;
            innerorder.push_back(temp);
        }
        printPostOrders(preorder, innerorder);
        cout << endl;
    }
    return 0;
}