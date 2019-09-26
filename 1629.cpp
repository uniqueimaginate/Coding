#include <iostream>

using namespace std;

int main(){

    int a;
    int b;
    int c;
    int result = 1;
    cin >> a >> b >> c;
    long long arr[100];
    long long data[100];
    int i=0;
    while(b != 0){
        arr[i++] = b % 2;
        b /= 2;
    }
    for(int j=0; j<i; j++){
        if(j==0)
            data[j] = a;
        else
            data[j] = (data[j-1] * data[j-1]) % c;
        if(arr[j]==1){
            result = (result * data[j])%c;
        }
    }

    cout << result << '\n';
    return 0;
}