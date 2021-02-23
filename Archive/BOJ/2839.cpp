#include <bits/stdc++.h>

using namespace std;

int DP[5001];

int main(){
    int c; cin >> c;
    fill(DP, DP+5001, -1);

    DP[3] = 1;
    DP[5] = 1;

    for(int i=6; i<=5000; ++i){
        int a = DP[i-3];
        int b = DP[i-5];
        if(a != -1 && b != -1){
            DP[i] = min(a, b) + 1;
        } else if(a != -1){
            DP[i] = a + 1;
        } else if(b != -1){
            DP[i] = b + 1;
        } else{}
    }

    cout << DP[c] << endl;
}
