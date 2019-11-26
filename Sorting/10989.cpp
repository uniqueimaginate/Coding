#include <iostream>
#include <algorithm>
#define ARR_SIZE 10010

using namespace std;
int N;
int arr[ARR_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        arr[temp % ARR_SIZE]++;
    }
    for(int i=0; i<ARR_SIZE; i++){
        if(arr[i] == 0) continue;
        else{
            for(int j=0; j<arr[i]; j++){
                cout << i << '\n';
            }
        }
    }
    return 0;
}