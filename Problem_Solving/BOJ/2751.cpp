#include <iostream>
#include <algorithm>

using namespace std;
int arr[1000010];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    int i=0;
    cin >> num;
    while(num--){
        cin >> arr[i];
        i++;
    }
    sort(arr, arr+i);
    for(int j=0; j<i; j++){
        cout << arr[j] << '\n';
    }
    return 0;
}
