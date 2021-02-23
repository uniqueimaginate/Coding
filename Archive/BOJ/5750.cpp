#include <bits/stdc++.h>

using namespace std;

int arr[1001];
int num;
int main(){
    cin >> num;

    for(int i=0; i<num; ++i){
        cin >> arr[i];
    }

    sort(arr, arr+num);

    for(int i=0; i<num; ++i){
        cout << arr[i] << endl;
    }
    return 0;
}