#include <iostream>

using namespace std;

int DP[16];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    int arr[2][16];

    cin >> a;

    for(int i=1; i<=a; i++){
        cin >> arr[0][i] >> arr[1][i];
    }

    for(int i=1; i<=a; i++){
        for(int j=1; j<=i; j++){
            if(j + arr[0][j] - 1 <= i){
                int temp = DP[j-1] + arr[1][j];
                if(temp > DP[i]) DP[i] = temp;
            }
        }
    }

    // for(int i=1; i<=a; i++){
    //     cout << DP[i] << " ";
    // }
    // cout << '\n';

    cout << DP[a] << '\n';


    return 0;
}
