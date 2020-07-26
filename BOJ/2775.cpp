#include <bits/stdc++.h>

using namespace std;

int apartment[16][16];
int c;
int main(){
    cin >> c;

    for(int i=1; i<=15; ++i){
        apartment[0][i] = i;
    }

    for(int i=1; i<=15; ++i){
        for(int j=1; j<=15; ++j){
            apartment[i][j] = apartment[i][j-1] + apartment[i-1][j];
        }
    }

    while(c--){
        int n,k; cin >> n >> k;
        cout << apartment[n][k] << endl;
    }
}