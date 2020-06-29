#include <iostream>
#include <cstdio>
#define SIZE 1005

using namespace std;

int n;
int Max;
int sum;

int main(){


    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int temp;
        scanf("%d", &temp);
        sum += temp;
        if(temp > Max){
            Max = temp;
        }
    }

    cout << (float)sum / (float)Max << endl;
    cout << (float)sum / (float)100 * (float)Max << endl;
}