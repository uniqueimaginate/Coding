#include <bits/stdc++.h>
#define MAX __INT_MAX__
using namespace std;

int dp[50001];

int result;

int main(){
    int N; cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2; i<=N; ++i){
        int minN = MAX;
        for(int j=1; j*j<=i; ++j){
            int temp = i - j * j;
            minN = min(minN, dp[temp]);
        }

        dp[i] = minN + 1;
    }

    cout << dp[N] << endl;
}