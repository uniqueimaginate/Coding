#include <iostream>
#include <vector>
#define SIZE 10000000
using namespace std;

int N;
int arr[SIZE];
vector<int> vec;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    arr[0] = 1;
    arr[1] = 1;
    cin >> N;
    for(int i=2; i*i<SIZE; i++){
        for(int j=i+i; j<SIZE; j += i){
            arr[j] = 1;
        }
    }

    for(int i=2; i<SIZE; i++){
        if(arr[i] == 0)
            vec.push_back(i);
    }

    int i=0;
    while(1){
        if(N == 1) break;
        while(1){
            int j = vec[i];
            if(N % j == 0){
                cout << j << '\n';
                N /= j;
            }
            else{
                i++;
            }
            if(N==1) break;
        }
    }
    return 0;
}