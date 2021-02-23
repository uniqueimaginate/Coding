#include <iostream>

using namespace std;

int arr[16];
int N,r,c;
int total;

void func(int num1, int num2, int len){
    if(num1 == r && num2 == c){
        cout << total << endl;
        exit(0);
    }
    if(len==1){
        total++;
        return;
    }
    if(!(num1 <= r && r < num1 + len && num2 <= c && c <num2 + len)){
        total += len * len;
        return;
    }

    func(num1, num2, len/2);
    func(num1, num2 + len/2, len/2);
    func(num1 + len/2, num2, len/2);
    func(num1 + len/2, num2 + len/2, len/2);
}

int main(){
    cin >> N >> r >> c;
    arr[1] = 2;
    for(int i=2; i<16; i++){
        arr[i] = arr[i-1] * 2;
    }

    func(0,0, arr[N]);
}