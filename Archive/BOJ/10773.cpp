#include <bits/stdc++.h>

using namespace std;

int main(){
    int c;
    cin >> c;
    vector<int> vec;
    while(c--){
        int temp; cin >> temp;
        if(temp != 0) vec.push_back(temp);
        else vec.pop_back();
    }
    int sum = 0;
    for(auto i : vec){
        sum += i;
    }

    cout << sum << endl;
}