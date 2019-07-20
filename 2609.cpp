#include <cstdio>

int gcd(int a, int b){
    int big;
    int small;
    if(a >= b){
        big = a;
        small = b;
    }
    else{
        big = b;
        small = a;
    }
    // printf("%d %d", big, small);
    while(big % small != 0){
        int temp = big;
        big = small;
        small = temp % small;
    }
    return small;
}

int lcm(int a, int b, int c){
    return a*b/c;
}

int main(){
    int a,b;
    scanf("%d %d", &a, &b);
    int _gcd = gcd(a,b);
    int _lcm = lcm(a,b,_gcd);
    printf("%d\n",_gcd);
    printf("%d\n", _lcm);
}