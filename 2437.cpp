#include <iostream>
#include <algorithm>
using namespace std;

int num;
int arr[1001];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num;
    for(int i=0; i < num; ++i){
        cin >> arr[i];
    }
    sort(arr, arr+num);

    int min_wght = 1;
    for(int i = 0; i < num; ++i){
        if(arr[i] > min_wght){
            break;
        }
        min_wght += arr[i];
    }

    cout << min_wght << '\n';
}