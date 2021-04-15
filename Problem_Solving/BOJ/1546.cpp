#include <iostream>
#include <cstdio>
#define SIZE 1005

using namespace std;

int n;
int Max;
int sum;
int arr[SIZE];
double result[SIZE];

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; ++i){
        scanf("%d", &arr[i]);

        if(Max < arr[i])
            Max = arr[i];
    }

    double sum = 0.0f;
    for(int i=0; i<n; ++i){
        result[i] = (double)arr[i] / Max * 100;
        sum += result[i];
    }

    printf("%.6lf\n", sum / n);
}