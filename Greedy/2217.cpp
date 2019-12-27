#include <iostream>
#include <algorithm>
#define SIZE 100001
using namespace std;

int N;
int arr[SIZE];

bool compare(int a, int b){
    return a > b;
}

int main(){
    int max = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N, compare);
    for(int i=0; i<N; i++){
        if(arr[i] * (i+1) > max)
            max = arr[i] * (i+1);
    }
    cout << max << endl;
}