#include <cstdio>

int main(void)
{
    int num;
    int place;

    scanf("%d %d", &num, &place);

    long long DP[201][201] = {0,};

    for(int i=1; i<=place; i++){
        DP[1][i] = i;
    }

    for(int i=2; i<=num; i++){
        for(int j=1; j<=place; j++){
            DP[i][j] = (DP[i][j-1] + DP[i-1][j])%1000000000;
        }
    }

    printf("%lld", DP[num][place]);
    return 0;
}

