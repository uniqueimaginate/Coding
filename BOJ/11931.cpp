#include <bits/stdc++.h>
#define RANGE 1000000
using namespace std;

int arr[2*RANGE+1];
int num;

bool smaller(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> num;

    for(int i=0; i<num; ++i){
        int temp; cin >> temp;

        arr[temp+RANGE] = 1;
    }

    for(int i=2*RANGE; i>=0; --i){
        if(arr[i]) cout << i-RANGE << '\n';
    }

    return 0;
}