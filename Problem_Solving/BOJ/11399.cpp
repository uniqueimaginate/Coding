#include <bits/stdc++.h>

using namespace std;

int C;

int main(){
    cin >> C;
    vector<int> vec(C);

    for(auto &v : vec){
        cin >> v;
    }

    sort(vec.begin(), vec.end());

    int *arr = new int[C];

    arr[0] = vec[0];

    for(int i=1; i<vec.size(); ++i){
        arr[i] = vec[i] + arr[i-1];
    }
    int result = 0;
    for(int i=0; i<C; ++i){
        result += arr[i];
    }

    cout << result << endl;
}