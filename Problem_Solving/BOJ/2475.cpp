#include <cstdio>

int main(){
    int i = 5;
    int sum=0;
    while(i--){
        int temp;
        scanf("%d", &temp);
        sum += temp*temp;
    }
    printf("%d\n", sum % 10);
}