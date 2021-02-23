#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int C;
vector<int> vec;
map<int, int> result;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> C;
    for(int i=0; i<C; ++i){
        int temp; cin >> temp;
        vec.push_back(temp);
    }
    vector<int> copy(vec);

    sort(vec.begin(), vec.end());

    result[vec[0]] = 0;
    int k = 1;
    for(int i=1; i<C; ++i){
        if(vec[i] == vec[i-1]) continue;
        else{
            result[vec[i]] = k++;
        }
    }

    for(auto i : copy){
        cout << result[i] << " ";
    }
    cout << endl;
}