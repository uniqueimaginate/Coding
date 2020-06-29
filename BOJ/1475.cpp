#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    int arr[10]={0,};
    cin >> a;
    if(a==0){
        cout << "1"<< '\n';
        return 0;
    }
    while(a != 0){
        int temp = a % 10;
        if(temp == 9)
            arr[6]++;
        else
            arr[temp]++;
        a /= 10;
    }
    if(arr[6]%2 == 0)
        arr[6] /= 2;
    else
        arr[6] = arr[6]/2 + 1;

    int max = 0;
    for(int i=0; i<9; i++){
        if(arr[i] > max)
            max = arr[i];
    }
    
    cout << max << '\n';
    return 0;
}