#include <iostream>
#define div 15746;
using namespace std;

int arr[10000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    cin >> a;

    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for(int i=3; i<=a; i++){
        arr[i] = (arr[i-1] + arr[i-2])%div;
    }

    cout << arr[a] << '\n';
    return 0;
}