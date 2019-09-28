#include <cstdio>

int Max(int a, int b){ return a > b ? a : b;}

int main(void)
{
    int N;
    int arr[1001];
    int DP[1001]{0,};
    DP[0] = 0;

    scanf("%d", &N);

    for(int i=1; i<=N; i++){
        scanf("%d", &arr[i]);
    }

    int max = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=i; j++){
            DP[i] = Max(max, DP[i-j]+arr[j]);
            max = DP[i];
        }
    }
    
    printf("%d", DP[N]);
    return 0;
}

