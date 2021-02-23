#include <bits/stdc++.h>
#define endl '\n'
#define bb ios::sync_with_stdio(false);cin.out(NULL);cout.out(NULL);

using namespace std;

char arr[1025][1025];

void printStar(int start, int end, int n){
    if(n == 0){
        arr[start][end] = '*';
        return;
    }

    printStar(start, end, n-1);
    printStar(start, end + pow(2,n-1), n-1);
    printStar(start + pow(2, n-1), end, n-1);
    
}

int main(){
    int n; cin >> n;
    memset(arr, ' ', sizeof(arr));
    printStar(0, 0, n);

    for(int i=0; i<pow(2,n); ++i){
        for(int j=0; j<pow(2,n)-i; ++j){
            cout << arr[i][j];
        }
        cout << endl;
    }
    return 0;
}