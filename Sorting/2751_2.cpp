#include <iostream>
#define MAX_SIZE 1000001
using namespace std;

int arr[MAX_SIZE];
int temp[MAX_SIZE];

void merge(int st, int en){
    int mid = (st+en)/2;
    int idx0 = st;
    int idx1 = st;
    int idx2 = mid;

    while(idx1 < mid && idx2 < en){
        if(arr[idx1] < arr[idx2]){
            temp[idx0++] = arr[idx1++];
        }
        else{
            temp[idx0++] = arr[idx2++];
        }
    }

    while(idx1 < mid){
        temp[idx0++] = arr[idx1++];
    }
    while(idx2 < en){
        temp[idx0++] = arr[idx2++];
    }
    for(int i=st; i<en; i++){
        arr[i] = temp[i];
    }
}

void merge_sort(int st, int en){
    if(en - st == 1) return;
    if(en - st == 2){
        if(arr[st] > arr[st+1]){
            arr[st] = arr[st] ^ arr[st+1];
            arr[st+1] = arr[st] ^ arr[st+1];
            arr[st] = arr[st] ^ arr[st+1];
        }
        return;
    }
    int mid = (st + en) / 2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st,en);
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    merge_sort(0,N);
    for(int i=0; i<N; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}