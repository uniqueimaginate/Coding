#include <cstdio>

int main()
{
    int num;
    int total = 0;
    scanf("%d", &num);
    for(int i=0; i<num; i++){
        int temp = 0;
        scanf("%1d", &temp);
        total += temp;
    }
    
    printf("%d", total);
}
