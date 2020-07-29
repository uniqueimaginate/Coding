#include <bits/stdc++.h>

using namespace std;

int c;
int arr[100][100];

int main(){
    cin >> c;
    while(c--){
        int a,b; cin >> a >> b;
        for(int i=0; i<10; ++i){
           for(int j=0; j<10; ++j){
               arr[a+i][b+j] = 1;
           }
        }
    }
    int result = 0;
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            if(arr[i][j] == 1) result++;
        }
    }
    cout << result << endl;
    return 0;
}