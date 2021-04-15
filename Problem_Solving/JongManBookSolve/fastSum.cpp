#include <iostream>

using namespace std;

// add from 1 to n
// using divide & conquer

int fastSum(int n){
    if(n==1) return 1;
    if(n % 2 == 1) return fastSum(n-1) + n;     // when n is odd
    return 2*fastSum(n/2) + (n*n)/4;            // when n is even
}

int main(){
    int n = 10;
    cout << fastSum(10) << endl;
}    