#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int C;
vector<int> vec;

bool solve(){
    int previous = vec[0];
    for(int i=1; i<vec.size(); ++i){
        if(abs(previous - vec[i]) > 1) return false;
        previous = vec[i];
    }
    return true;
}

int main(){
    cin >> C;
    for(int i=0; i<C; ++i){
        int num; cin >> num;
        for(int j=0; j<num; ++j){
            int temp; cin >> temp;
            vec.push_back(temp);
        }
        sort(vec.begin(), vec.end());
        solve() ? cout << "YES" << endl : cout << "NO" << endl;
        vec.clear();
    }
}