#include <iostream>

using namespace std;

int N,K, i, j, arr[100];

int main(){
    cin >> N >> K;

    for(i=0; i<N; i++){
        int temp;
        cin >> temp;
        for(j=0; j<K; j++){
            if(temp > arr[j]){
                arr[j] = temp;
                break;
            }
        }

        if(j==K){
            cout << "NO" << endl;
            break;
        }
    }

    if(i == N){
        cout << "YES" << endl;
    }
}