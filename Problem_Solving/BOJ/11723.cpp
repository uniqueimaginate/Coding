#include <bits/stdc++.h>

using namespace std;

int arr[21];
int c;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c;
    while(c--){
        string temp; cin >> temp;
        if(temp == "add"){
            int temp; cin >> temp;
            arr[temp] = 1;
        } else if(temp == "check"){
            int temp; cin >> temp;
            if(arr[temp]) cout << "1" << '\n';
            else cout << "0" << '\n';
        } else if(temp == "remove"){
            int temp; cin >> temp;
            arr[temp] = 0;
        } else if(temp == "toggle"){
            int temp; cin >> temp;
            if(arr[temp]) arr[temp] = 0;
            else arr[temp] = 1;
        } else if(temp == "empty"){
            memset(arr, 0, sizeof(arr));
        } else{
            fill(arr, arr+21, 1);
        }
    }
}