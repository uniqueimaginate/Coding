#include <cstdio>

int main(void)
{
    int num;
    int arr[1001];
    int DP[1001];
    DP[0] = 0;
    arr[0] = 0;
    int max=0;

    scanf("%d", &num);
    for(int i=1; i<=num; i++){
        scanf("%d", &arr[i]);
    }


    for(int i=1; i<=num; i++){
        int localMax = 0;
        for(int j=0; j<i; j++){
            if(arr[i] > arr[j]){
                if(localMax < DP[j])
                    localMax = DP[j];
            }
        }
        DP[i] = localMax + 1;
        if(max < DP[i])
            max = DP[i];
    }
    printf("%d", max);
}
