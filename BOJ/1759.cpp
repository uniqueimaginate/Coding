#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

char arr[16];
char tmp[16];
int N,M;


void dfs(int start, int cnt){
    if(cnt == N){
        int vowelN = 0, consonant = 0;
        for(int i=0; i<N; ++i){
            if(tmp[i] == 'a' || tmp[i] == 'e' || tmp[i] == 'i' || tmp[i] == 'o' || tmp[i] == 'u') {
                vowelN++;
            }
        }
        consonant = N - vowelN;

        if(vowelN >= 1 && consonant >= 2){
            for(int i=0; i<N; ++i){
                cout << tmp[i];
            }
            cout << endl;
        }
        return;
    }

    for(int i=start; i<M; ++i){
        tmp[cnt] = arr[i];
        dfs(i+1, cnt+1);
    }
}

int main(){
    cin >> N >> M;
    for(int i=0; i<M; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+M);
    dfs(0,0);

    return 0;
}