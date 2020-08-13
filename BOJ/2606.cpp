#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;

int C;
bool visited[101];
bool connections[101][101];

int result;
queue<int> q;

void countVirus(){
    while(!q.empty()){
        int here = q.front();
        if(visited[here]){
            q.pop(); continue;
        };
        // cout << "here : " << here << endl;
        q.pop();
        visited[here] = true;


        for(int i=1; i<101; ++i){
            if(visited[i]) continue;
            if(connections[here][i]) {q.push(i); }
        }
        ++result;
    }
}

int main(){
    cin >> C;

    int num; cin >> num;
    while(num--){
        int a, b;
        cin >> a >> b;
        connections[a][b] = true;
        connections[b][a] = true;
    }

    q.push(1);
    countVirus();

    cout << result-1 << endl;
}