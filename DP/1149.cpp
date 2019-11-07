#include <iostream>

using namespace std;

int arr[1010][3];
int DP[1000][3];

int min(int a, int b){return a < b ? a : b;}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int result = 0;

    cin >> num;
    for(int i=1; i<=num; i++){
        for(int j=0; j<3; j++){
            cin >> arr[i][j];
        }
    }
    DP[0][0] = 0;
    DP[0][1] = 0;
    DP[0][2] = 0;

    int i;
    for(i=1; i<=num; i++){
        DP[i][0] = arr[i][0] + min(DP[i-1][1], DP[i-1][2]);
        DP[i][1] = arr[i][1] + min(DP[i-1][0], DP[i-1][2]);
        DP[i][2] = arr[i][2] + min(DP[i-1][0], DP[i-1][1]);

    }

    int min1 = min(min(DP[i-1][0], DP[i-1][1]), DP[i-1][2]);

    cout << min1 << '\n';
    return 0;
}