#include <bits/stdc++.h>
#define MIN -987654321
using namespace std;

vector<int> vec;

int c;
int maxIndex;
int maxResult;

int main(){
    cin >> c;
    while(c--){
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    int minN = MIN;
    int temp = 0;
    for(auto i : vec){
        if(i > minN){
            minN = i;
            temp = 0;
        } else{
            temp++;
        }
        maxResult = max(maxResult, temp);
    }

    cout << maxResult << endl;

}