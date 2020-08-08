#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

map<string, int> m;
map<string, int> result;
int N, M;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    while(N--){
        string temp; cin >> temp;
        m[temp] = 1;
    }

    while(M--){
        string temp; cin >> temp;
        if(m.find(temp) != m.end()){
            result[temp] = 1;
        }
    }

    cout << result.size() << endl;
    for(auto i : result){
        cout << i.first << endl;
    }
}