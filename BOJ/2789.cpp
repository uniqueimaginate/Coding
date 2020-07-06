#include <iostream>

using namespace std;

int arr[100];

int main(){
    int N,M;
    cin >> N >> M;
    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

    int mins = 987654321;
    for(int i=0; i<N-2; ++i){
        for(int j=i+1; j<N-1; ++j){
            for(int k=j+1; k<N; ++k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum > M)
                    continue;
                else{
                    if(M - sum < mins)
                        mins = M-sum;
                }
            }
        }
    }
    cout << M - mins << endl;
}