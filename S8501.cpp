#include <cstdio>


int main(void)
{
    int num;
    long long DP[1001];
    long long Fac[1001];
    DP[0] = 0;
    DP[1] = 0;
    Fac[0] = 1;
    for(int i=1; i<1001; i++){
        Fac[i] = (Fac[i-1] * i) % 1000000007;
    }

    for(int i=2; i<=1000; i++){
        DP[i] = (i * DP[i-1] + (i/2) * Fac[i-1]) % 1000000007;
    }
    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        int temp;
        scanf("%d", &temp);
        printf("#%d %lld\n", i, DP[temp]);
    }
    return 0;
}
