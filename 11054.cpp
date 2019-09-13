#include <cstdio>

int Max(int a, int b){ return a > b ? a : b; }

int main(void)
{
    int front[1001];
    int back[1001];
    int arr[1001];
    arr[0] = 0;
    front[0] = 0;
    back[0] = 0;

    int num;
    scanf("%d", &num);

    for(int i=1; i<=num; i++){
        scanf("%d", &arr[i]);
    }

    //from the front
    for(int i=1; i<=num; i++){
        int increase = 0;
        for(int j=1; j<i; j++){
            if(arr[j] < arr[i]){
                if(front[j] > increase)
                    increase = front[j];
            }
        }
        front[i] = increase + 1;
    }

    //from the back
    for(int i=num; i>0; i--){
        int decrease = 0;
        for(int j=num; j>i; j--){
            if(arr[j] < arr[i]){
                if(back[j] > decrease)
                    decrease = back[j];
            }
        }
        back[i] = decrease + 1;
    }

    int max = 0;
    for(int i=1; i<=num; i++){
        max = Max(max, front[i]+back[i]-1);
    }

    printf("%d", max);

    return 0;
}
