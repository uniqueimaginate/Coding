#include <bits/stdc++.h>
#define endl '\n'
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int DP[50];


char doMoo(int a){
    if(a==1) return 'm';
    if(a==2 || a==3) return 'o';

    int i = 0;
    while(DP[i] < a) i++;
    if(DP[i] == a) return 'o';
    if(a - DP[i-1] == 1) return 'm';
    if(a - DP[i-1] <= i + 3) return 'o';
    return doMoo(a - DP[i-1] - (i+3));
}

int main(){
    bb; int num;
    
    cin >> num;

    DP[0] = 3;
    for(int i=1; i<40; ++i){
        DP[i] = DP[i-1] * 2 + i + 3;
    }

    cout << doMoo(num) << endl;
}