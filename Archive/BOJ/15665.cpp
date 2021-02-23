#include <bits/stdc++.h>

using namespace std;

int N,M;
int arr[10];
int tmp[10];

void dfs(int cnt){
    if(cnt == M){
        for(int i=0; i<M; ++i){
            cout << tmp[i] << " ";
        }
        cout << '\n';
        return;
    }

    int temp = 0;
    for(int i=0; i<N; ++i){
        if(temp == arr[i]) continue;
        tmp[cnt] = arr[i];
        temp = arr[i];
        dfs(cnt+1);
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+N);
    dfs(0);
    return 0;
}