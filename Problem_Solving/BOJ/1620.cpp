#include <bits/stdc++.h>

using namespace std;

map<string, string> m;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N,M; cin >> N >> M;
    int i = 1;
    while(N--){
        string num = to_string(i++);
        string str; cin >> str;
        m[num] = str;
        m[str] = num;
    }

    while(M--){
        string str; cin >> str;
        cout << m[str] << '\n';
    }
}