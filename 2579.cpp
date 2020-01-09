#include <cstdio>

int Max(int a, int b){ return a > b ? a : b; }

int main(void)
{
    int num;
    scanf("%d", &num);
    int *DP = new int[num+1];
    int *arr = new int[num+1];
    DP[0] = 0;
    arr[0] = 0;


    for(int i=1; i<=num; i++){
        scanf("%d", &arr[i]);
    }

    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];

    for(int i=3; i<=num; i++){
        DP[i] = Max(DP[i-2] + arr[i], DP[i-3] + arr[i-1] + arr[i]);
    }

    printf("%d", DP[num]);

    return 0;
}
