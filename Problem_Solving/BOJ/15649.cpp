#include <iostream>
#define MAX 9

using namespace std;

int issue[MAX];
int arr[MAX];
int N,M;

void func(int *issue, int *arr, int _i){
    if(_i == M){
        for(int i=0; i<M; i++) cout << arr[i] + 1 << ' ';
        cout << '\n';
        return;
    }

    for(int i=0; i<N; i++){
        if(!issue[i]){
            issue[i] = 1;
            arr[_i] = i;
            func(issue, arr, _i+1);
            issue[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    func(issue, arr, 0);

    return 0;
}