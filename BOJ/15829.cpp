#include <bits/stdc++.h>

using namespace std;

int toNumber(char ch){ return ch - 'a' + 1;}
long long arrPow[51];

long long sum;

int main(){
    int n;
    string str;
    cin >> n >> str;

    arrPow[0] = 1;

    for(int i=1; i<51; ++i){
        arrPow[i] = 31 * arrPow[i-1];
        arrPow[i] %= 1234567891;
    }

    for(int i=0; i<n; ++i){
        sum += (toNumber(str[i]) * arrPow[i]);
        sum %= 1234567891;
    }


    cout << sum << endl;
}