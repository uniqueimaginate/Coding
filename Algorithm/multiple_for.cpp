#include <iostream>
#include <vector>
using namespace std;

int arr[8] = {0,1,2,3,4,5,6,7};

vector<int> picked;

void printPicked(vector<int>& picked){
    for(int i=0; i<picked.size(); i++){
        cout << picked.at(i) << " ";
    }
}

void recursive_multiple_for(int n, vector<int>& picked, int topick){
    if(topick == 0){
        printPicked(picked);
        cout << endl;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;

    for(int next = smallest; next < n; ++next){
        picked.push_back(next);
        recursive_multiple_for(n, picked, topick - 1);
        picked.pop_back();
    }
}

void multiple_for(){
    for(int i=0; i<8; ++i){
        for(int j=i+1; j<8; ++j){
            for(int k = j+1; k<8; ++k){
                for(int l = k+1; l < 8; ++l){
                    cout << i << " " << j << " " << k << " " << l << endl;
                }
            }
        }
    }
}

int main(){
    multiple_for();
    recursive_multiple_for(7, picked, 4);
}