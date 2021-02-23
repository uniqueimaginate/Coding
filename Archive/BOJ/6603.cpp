#include <bits/stdc++.h>

using namespace std;

int K;
int arr[20];
int tmp[20];

void dfs(int start, int cnt){
    if(cnt == 6){
        for(int i=0; i<6; ++i){
            cout << tmp[i] << " ";
        }
        cout << endl;
    }

    for(int i = start; i<K; ++i){
        tmp[cnt] = arr[i];
        dfs(i + 1, cnt + 1);
    }
}

int main(){
    while(cin >> K && K){
        for(int i=0; i<K; ++i){
            cin >> arr[i];
        }

        dfs(0,0);

        cout << endl;
    }
}