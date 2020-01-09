#include <iostream>
#define MAX 9

using namespace std;

int arr[MAX];
int N,M;

void func(int *arr, int num){
    if(num == M){
        for(int i=0; i<M; i++) cout << arr[i] + 1 << ' ';
        cout << '\n';
        return;
    }
    int pos = 0;
    if(num != 0) pos = arr[num-1];
    for(int i=pos; i<N; i++){
        arr[num] = i;
        func(arr, num+1);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    func(arr, 0);

    return 0;
}