#include <iostream>
#define MAX_SIZE 101
#define INF 987654321
#define MIN(a, b) (((a) < (b)) ? (a) : (b)); 
using namespace std;

int arr[MAX_SIZE][MAX_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j)
                arr[i][j] = 0;
            else
                arr[i][j] = INF;
        }
    }

    for(int i=0; i<M; i++){
        int row,col,w;
        cin >> row >> col >> w;
        if(w < arr[row][col]){
            arr[row][col] = w;
        }
    }

    

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(arr[i][k] != INF && arr[k][j] != INF)
                    arr[i][j] = MIN(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(arr[i][j] == INF){
                cout << "0" << " ";
            }
            else{
                cout << arr[i][j] << " ";
            }
        }
        cout << '\n';
    }


    return 0;
}