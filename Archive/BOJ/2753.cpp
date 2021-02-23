#include <cstdio>

int is(int n){
    if(n% 400 == 0) return 1;
    if((n % 4 == 0) && (n % 100 != 0)) return 1;

    return 0;
}

int main(){
    int n;
    scanf("%d", &n);

    printf("%d\n",is(n));
}