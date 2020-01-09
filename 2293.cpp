#include <iostream>

using namespace std;

int arr[110][10010];
int n,k;
int main(){
    cin >> n >> k;
    for(int i=0; i<n; i++){
        int temp;
        cin >> temp;
        arr[i][0] = temp;
    }

    // init;
    for(int i=1; i<=k; i++){
        if(k % arr[0][0] == 0){
            arr[0][i] = 1;
        }
    }

    

    return 0;
}