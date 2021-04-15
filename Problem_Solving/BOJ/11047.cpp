#include <iostream>
#define MAX_SIZE 12
using namespace std;

int N, K;
int arr[MAX_SIZE];
int result[MAX_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }

    for(int i=N-1; i>=0; i--){
        if(K / arr[i] == 0) continue;
        else{
            result[i] = K / arr[i];
            K -= (result[i] * arr[i]);
        }
    }
    int count = 0;
    for(int i=0; i<N; i++){
        count += result[i];
    }
    cout << count << '\n';

    return 0;
}