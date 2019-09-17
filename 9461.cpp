#include <cstdio>

int main(void)
{
    int num;
    scanf("%d", &num);
    long long DP[101] = {};

    DP[1] = 1;
    DP[2] = 1;
    DP[3] = 1;
    DP[4] = 2;
    DP[5] = 2;

    for(int i=6; i<101; i++){
        DP[i] = DP[i-1] + DP[i-5];
    }

    for(int i=0; i<num; i++){
        int temp;
        scanf("%d", &temp);
        printf("%lld\n", DP[temp]);
    }

    return 0;
}

