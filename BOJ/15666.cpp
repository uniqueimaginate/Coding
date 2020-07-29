#include <bits/stdc++.h>

using namespace std;

int arr[10];
int tmp[10];

int N,M;

void dfs(int start, int cnt){
    if(cnt == M){
        for(int i=0; i<M; ++i){
            cout << tmp[i] << " ";
        }
        cout << endl;
        return;
    }
    int temp = 0;
    for(int i=start; i<N; ++i){
        if(temp == arr[i]) continue;
        tmp[cnt] = arr[i];
        temp = arr[i];
        dfs(i, cnt+1);
    }
}

int main(){
    cin >> N >> M;

    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    dfs(0,0);
    return 0;
}