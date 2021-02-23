#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <utility>
#define SIZE 1010

using namespace std;
int row, col;

int arr[SIZE][SIZE];
vector< pair <int, int > > vec;

void bfs(){

}


int main(){
    scanf("%d %d", &row, &col);

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            scanf("%1d", &arr[i][j]);
        }
    }

    return 0;
}