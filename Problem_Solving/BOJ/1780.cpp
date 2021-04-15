#include <iostream>
#define ARR_SIZE 2200
using namespace std;

int arr[ARR_SIZE][ARR_SIZE];
int N;
int result[3];
int temp[3];

void recursive(int x, int y, int num){
    temp[0] = 0;
    temp[1] = 0;
    temp[2] = 0;
    for(int i=0; i<num; i++){
        for(int j=0; j<num; j++){
            if(arr[x+i][y+j] == -1){
                temp[0]++;
            }
            else if(arr[x+i][y+j] == 0){
                temp[1]++;
            }
            else if(arr[x+i][y+j] == 1){
                temp[2]++;
            }
        }
    }

    // 종료조건
    if(temp[0] == num*num){
        result[0]++;
        return;
    }
    else if(temp[1] == num*num){
        result[1]++;
        return;
    }
    else if(temp[2] == num*num){
        result[2]++;
        return;
    }
    else if(num == 3){
        result[0] += temp[0];
        result[1] += temp[1];
        result[2] += temp[2];
        return;
    }

    // 9 개로 쪼개기
    recursive(x, y, num / 3);
    recursive(x, y + num / 3, num / 3);
    recursive(x, y + 2 * num / 3, num / 3);

    recursive(x + num / 3, y, num / 3);
    recursive(x + num / 3, y + num / 3, num / 3);
    recursive(x + num / 3, y + 2 * num / 3, num / 3);

    recursive(x + 2 * num / 3, y, num / 3);
    recursive(x + 2 * num / 3, y + num / 3, num / 3);
    recursive(x + 2 * num / 3, y + 2 * num / 3, num / 3);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }

    recursive(0, 0, N);    
    cout << result[0] << '\n';
    cout << result[1] << '\n';
    cout << result[2] << '\n';

    return 0;
}