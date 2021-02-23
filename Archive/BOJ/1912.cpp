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

    for(int i=2; i<=num; i++){
        if(DP[i-1] + arr[i] >= arr[i]) {
            DP[i] = DP[i-1] + arr[i];
        }
        else
            DP[i] = arr[i];
    }

    int max = arr[1];
    for(int i=1; i<=num; i++){
        max = Max(max, DP[i]);
    }

    printf("%d", max);
    return 0;
}
