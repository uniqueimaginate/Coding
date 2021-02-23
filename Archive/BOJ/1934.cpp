#include <iostream>

using namespace std;

int gcd(int a, int b){
    return !b ? a : gcd(b, a%b);
}

int main(){
    int N;
    cin >> N;
    while(N--){
        int a,b;
        cin >> a >> b;
        cout << a*b/gcd(a,b) << endl;
    }

    return 0;
}