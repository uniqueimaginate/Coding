#include <cstdio>

int Min(int a, int b){ return a < b ? a : b; }

int main(void)
{
    int num;
    scanf("%d", &num);
    int DP[100001]{};
    DP[0] = 0;
    DP[1] = 1;


    for(int i=2; i<=num; i++){
        DP[i] = i;
        for(int j=2; j*j<=i; j++){
            DP[i] = Min(DP[i], DP[i - j*j] + 1);
        }
    }

    printf("%d", DP[num]);
    return 0;
}

