#include <iostream>
#include <algorithm>
#define ARR_SIZE 5000000

using namespace std;
int N,K;
int arr[ARR_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> K;

    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    sort(arr, arr+N);
    
    cout << arr[K-1] <<'\n';


    return 0;
}