#include <iostream>
#include <cstdio>

using namespace std;

int N,K;
int DP[10001];
int arr[101];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; ++i){
        int temp;
        cin >> temp;
        if(temp <= 10000){
            DP[temp] = 1;
            arr[i] = temp;
        }
    }

    for(int i=1; i<=K; ++i){
        if(DP[i])
            continue;
        else{
            int min = 1000000;
            for(int j=0; j<N; ++j){
                int pos = i - arr[j];
                if((pos > 0) && DP[pos]){
                    if(min > DP[pos] + 1){
                        min = DP[pos] + 1;
                    }
                }
            }
            if(min == 1000000)
                continue;
            else
                DP[i] = min;
        }
    }

    if(DP[K]){
        cout << DP[K] << '\n';
    }
    else{
        cout << "-1" << '\n';
    }

    return(0);
}