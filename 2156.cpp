#include <cstdio>

using namespace std;

int Max(int a, int b){ return a > b ? a : b; }

int main(void)
{
    int num;
    int arr[10001];
    int DP[10001];
    DP[0] = 0;
    arr[0] = 0;

    scanf("%d", &num);

    for(int i=1; i<=num; i++){
        scanf("%d", &arr[i]);
    }


    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];

    int max = 0;
    for(int i=3; i<=num; i++){
        int max = 0;
        max = Max(DP[i-1], DP[i-2] + arr[i]);
        max = Max(max, DP[i-3] + arr[i-1] + arr[i]);
        DP[i] = max;
    }

    printf("%d\n", DP[num]);
}
