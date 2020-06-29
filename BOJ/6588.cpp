#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#define SIZE 1000000
using namespace std;

vector<int> vec;
int arr[SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    // 에라토스테네스의 체
    for(int i=2; i*i<SIZE; i++){
        for(int j=i+i; j<SIZE; j+=i){
            arr[j] = 1;
        }
    }


    while(1){
        int temp;
        cin >> temp;
        if(temp == 0)   break;
        for(int i=2; i<=temp/2; i++){
            if(!arr[i] && !arr[temp-i]){
                cout << temp << " = " << i << " + " << temp-i << '\n';
                break;
            }
        }
    }

    return 0;
}