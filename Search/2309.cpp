#include <iostream>
#include <algorithm>

using namespace std;

int arr[9];
int sum = 0;
bool check = false;

int main(){
    for(int i=0; i<9; i++){
        cin >> arr[i];
        sum += arr[i];
    }

    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if((sum - (arr[i] + arr[j])) == 100){
                arr[i] = -1;
                arr[j] = -1;
                check = true;
                break;
            }
        }
        if(check)
            break;
    }
    sort(arr, arr+9);
    for(int i=2; i<9; i++){
        cout << arr[i] << endl;
    }
    return 0;
}