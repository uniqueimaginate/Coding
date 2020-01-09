#include <iostream>
#include <algorithm>
#define SIZE 10000
using namespace std;

int N;
int arr[SIZE];
long long result;

bool compare(int a, int b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N, compare);

    int temp = 0;
    bool flag = false;
    for(int i=0; i<N; i++){
        if(arr[i] <= 0){
            if(arr[i] == 0) flag = true;
            break;
        }
        if(temp == 0) temp = arr[i];
        else{
            if(arr[i] * temp > arr[i] + temp){
                result += temp * arr[i];
            }
            else{
                result += temp + arr[i];
            }
            temp = 0;
        }
    }
    result += temp;
    temp = 0;

    sort(arr, arr+N);
    for(int i=0; i<N; i++){
        if(arr[i] >= 0) break;
        if(temp == 0)   temp = arr[i];
        else{
            result += temp * arr[i];
            temp = 0;
        }
    }
    if(!flag) result += temp;


    cout << result << '\n';
    return 0;
}