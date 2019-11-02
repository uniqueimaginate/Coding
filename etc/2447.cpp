#include <iostream>

using namespace std;

char arr[2500][2500];

int num;

void func(int n1, int n2, int len){
    if(len == 1){
        arr[n1][n2] = '*';
        return;
    }
    func(n1, n2, len/3);
    func(n1, n2 + len/3, len/3);
    func(n1, n2 + 2 * len/3, len/3);

    func(n1 + len/3, n2, len/3);
    // func(n1 + len/3, n2 + len/3, len/3);
    func(n1 + len/3, n2 + 2 * len/3, len/3);

    func(n1 + 2 * len/3, n2, len/3);
    func(n1 + 2 * len/3, n2 + len/3, len/3);
    func(n1 + 2 * len/3, n2 + 2 * len/3, len/3);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> num;

    for(int i=0; i<2500; i++){
        for(int j=0; j<2500; j++){
            arr[i][j] = ' ';
        }
    }

    func(0,0,num);


    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
    return 0;
}