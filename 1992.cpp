#include <iostream>
#include <cstdio>

using namespace std;

int arr[64][64];

void func(int n1, int n2, int len){
    int check1 = 0;
    int check0 = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(arr[n1+i][n2+j] == 1){
                check1++;
            }
            else{
                check0++;
            }
        }
    }
    if(check1 == len * len){
        printf("1");
    }
    else if(check0 == len * len){
        printf("0");
    }
    else{
        printf("(");
        func(n1, n2, len/2);
        func(n1, n2 + len/2, len/2);
        func(n1 + len/2, n2, len/2);
        func(n1 + len/2, n2 + len/2, len/2);
        printf(")");
    }
}

int main(){

    int num;
    cin >> num;

    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            scanf("%1d", &arr[i][j]);
        }
    }
    func(0,0,num);
    printf("\n");

    return 0;
}