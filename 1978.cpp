#include <iostream>
#define SIZE 1001
using namespace std;

int arr[SIZE];
int N;
// 소수면 1이고 아니면 2

void prime(){
    for(int i=2; i<1001; i++){
        for(int j=1; j*i < 1001; j++){
            if(j==1 && arr[i*j] == 0){
                arr[i*j] = 1;
            }
            else
                arr[i*j] = 2;
        }
    }
}

int main(){
    cin >> N;
    int count = 0;
    prime();
    while(N--){
        int temp;
        cin >> temp;
        if(arr[temp] == 1)
            count++;
    }
    cout << count << endl;
    // for(int i=0; i<100; i++){
    //     cout << arr[i] << " ";
    // }
}
