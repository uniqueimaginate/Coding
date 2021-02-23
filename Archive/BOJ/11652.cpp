#include <iostream>
#include <algorithm>
#define ARR_SIZE 1000010
using namespace std;

int N;
long long arr[ARR_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int max_count=0;
    int count = 1;
    long long max_num = arr[0];
    long long temp = arr[0];

    if(N==1){
        cout << arr[0] << '\n';
        return 0;
    }
    for(int i=1; i<N; i++){
        if(arr[i] == temp){
            count++;
        }
        else{
            if(count > max_count){
                max_count = count;
                max_num = arr[i-1];
            }
            count = 1;
            temp = arr[i]; 
        }
    }

    if(count > max_count){
        max_num = arr[N-1];
    }

    cout << max_num << '\n';
    return 0;
}