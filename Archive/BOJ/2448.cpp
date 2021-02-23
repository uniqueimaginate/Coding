#include <iostream>

using namespace std;

char arr[3072][6144];

void func(int n1, int n2, int num){
    if(num == 3){
        arr[n1][n2] = '*';
        arr[n1+1][n2-1] = '*';
        arr[n1+1][n2+1] = '*';
        arr[n1+2][n2-2] = '*';
        arr[n1+2][n2-1] = '*';
        arr[n1+2][n2] = '*';
        arr[n1+2][n2+1] = '*';
        arr[n1+2][n2+2] = '*';
        return;
    }
    
    func(n1, n2, num/2);
    func(n1 + num/2, n2 - num/2, num/2);
    func(n1 + num/2, n2 + num/2, num/2);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int num;
    cin >> num;

    for(int i=0; i<3072; i++){
        for(int j=0; j<6144; j++){
            arr[i][j] = ' ';
        }
    }

    func(0, num-1, num);

    for(int i=0; i<num; i++){
        for(int j=0; j<num*2; j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}