#include <iostream>

using namespace std;


void merge(int *A, int N, int *B, int M){
    int *arr_sort = new int[N+M];
    int idx0=0;
    int idx1=0;
    int idx2=0;
    
    while(idx1 < N && idx2 < M){
        if(A[idx1] < B[idx2] ){
            arr_sort[idx0++] = A[idx1++];
        }
        else{
            arr_sort[idx0++] = B[idx2++];
        }
    }
    
    while(idx1 < N)
        arr_sort[idx0++] = A[idx1++];
    while(idx2 < M)
        arr_sort[idx0++] = B[idx2++];
    
    for(int i=0; i<N+M; i++){
        cout << arr_sort[i] << " ";
    }
    cout << '\n';
    delete[] arr_sort;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M;
    cin >> N >> M;
    int *A = new int[N];
    int *B = new int[M];
    int count = 0;

    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    for(int i=0; i<M; i++){
        cin >> B[i];
    }

    merge(A, N, B, M);

    delete[] A;
    delete[] B;
    return 0;
}