#include <iostream>
#include <cstdio>

using namespace std;

int Max(int& a, int& b){ return a > b ? a : b; }

int main(void)
{
    int num;
    int DP[2][100001];
    int arr[2][100001];

    scanf("%d", &num);

    for(int i=0; i<num; i++){
        int col;
        scanf("%d", &col);

        for(int k=0; k<2; k++){
            for(int j=1; j<=col; j++){
                scanf("%d", &arr[k][j]);
            }
        }

        DP[0][0] = 0; DP[1][0] = 0;
        DP[0][1] = arr[0][1]; DP[1][1] = arr[1][1];

        for(int j=2; j<=col; j++){
            DP[0][j] = Max(DP[1][j-1], DP[1][j-2]) + arr[0][j];
            DP[1][j] = Max(DP[0][j-1], DP[0][j-2]) + arr[1][j];
        }

        printf("%d\n", Max(DP[0][col], DP[1][col]));
    }
}