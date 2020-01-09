#include <iostream>
#include <string>

using namespace std;

int arr[52];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    arr[0] = 0;
    arr[1] = 1;
    for(int i=2; i<=40; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }

    int N;
    cin >> N;
    while(N--){
        int temp, zero = 0, one = 0;
        cin >> temp;
        string str = to_string(arr[temp]);
        for(int i=0; i<str.size(); i++){
            if(str[i] == '1') one++;
            if(str[i] == '0') zero++;
        }
        cout << zero << " " << one << '\n';
    }

    return 0;
}