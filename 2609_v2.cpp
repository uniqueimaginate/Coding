#include <iostream>

using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a%b) : a;
}

int lcm(int a, int b){
    return (a*b) / gcd(a,b);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a;
    int b;
    cin >> a >> b;
    cout << gcd(a,b) << '\n';
    cout << lcm(a,b);
    return 0;
}
