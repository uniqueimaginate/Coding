#include <bits/stdc++.h>

using namespace std;

int arr[10];
int tmp[10];
bool visit[10];
int N,M;

void dfs(int start, int cnt){
    if(cnt == M){
        for(int i=0; i<M; ++i){
            cout << tmp[i] << " ";
        }
        cout << endl;
    }
    int temp = 0;
    for(int i = 0; i<N; ++i){
        if(!visit[i] && temp != arr[i]){
            visit[i] = true;
            tmp[cnt] = arr[i];
            temp = arr[i];
            dfs(i+1, cnt+1);
            visit[i] = false;
        }
        
        
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    dfs(0,0);
}