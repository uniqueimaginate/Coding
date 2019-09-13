#include <cstdio>

int main(void)
{
    int num;
    int arr[1001];
    int DP[1001];
    DP[0] = 0;
    arr[0] = 0;
    int Max=0;

    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=1; i<=num; i++){
        int max = 0;
        for(int j=0; j<i; j++){
            if(arr[i] < arr[j]){
                if(max < DP[j])
                    max = DP[j];
            }
        }
        DP[i] = max + 1;

        if(Max < DP[i])
            Max = DP[i];
    }
    
    printf("%d", Max);
}
