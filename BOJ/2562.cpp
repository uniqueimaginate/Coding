#include <cstdio>

int main(){
    
    int max = 0;
    int pos;
    for(int i=1; i<=9; i++){
        int temp;
        scanf("%d", &temp);
        if(max < temp){
            max = temp;
            pos = i;
        }
    } 

    printf("%d\n%d\n", max, pos);
}