#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;

int N, M;
bool arr[1001][1001];
bool visited[1001];

int ret;

queue<int> q;

int findComponents(){
    while(!q.empty()){
        int here = q.front();
        if(visited[here]){
            q.pop(); continue;
        };
        q.pop();
        visited[here] = true;

        for(int i=1; i<=N; ++i){
            if(visited[i]) continue;
            if(arr[here][i]) q.push(i);
        }
    }



    return 1;
}

int main(){
    bb;
    cin >> N >> M;

    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        arr[a][b] = true;
        arr[b][a] = true;
    }

    for(int i=1; i<=N; ++i){
        if(visited[i]) continue;
        q.push(i);
        ret += findComponents();
    }

    cout << ret << endl;
}