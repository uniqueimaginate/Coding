#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void func(int a, int b, int n){
    if(n==1){
        cout << a << ' ' << b << '\n';
        return;
    }
    int c = 6 - a - b;
    func(a,c, n-1);
    cout << a << ' ' << b << '\n';
    func(c, b, n-1);
}

int main(){
    int num;
    cin >> num;
    cout << (1<<num)-1 << endl;
    func(1,3,num);
}