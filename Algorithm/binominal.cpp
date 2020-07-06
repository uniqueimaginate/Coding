#include <iostream>

using namespace std;

long long cache[40][40];

long long binominal(int n, int r){
    if(r == 0 || n == r) return 1;
    else{
        return binominal(n-1, r-1) + binominal(n-1, r);
    }
}

long long binominal2(int n, int r){
    if(r == 0 || n == r) return 1;
    if(cache[n][r] != 0) return cache[n][r];
    return cache[n][r] = binominal2(n-1, r-1) + binominal2(n-1, r);
}

int main(){
    int n, r;
    cin >> n >> r;
    cout << binominal(n,r) << endl;
    cout << binominal2(n, r) << endl;
}