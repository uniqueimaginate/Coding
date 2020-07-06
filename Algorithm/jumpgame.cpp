#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int board[100][100];
int cache[100][100];
int C, n;

bool jumpgame(int y, int x){
    if(y >= n || x >= n) return false;
    if(y == n-1 && x == n-1) return true;
    int jumpSize = board[y][x];
    return jumpgame(y + jumpSize, x) || jumpgame(y, x + jumpSize);
}

int jumpgame2(int y, int x){
    if(y >= n || x >= n) return 0;
    if(y == n-1 && x == n-1) return 1;
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    int jumpSize = board[y][x];
    return ret = (jumpgame2(y + jumpSize, x) || jumpgame2(y, x + jumpSize));
}

int main(){
    cin >> C;
    memset(cache, -1, sizeof(cache));
    while(C--){
        cin >> n;
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                cin >> board[i][j];
            }
        }

        if(jumpgame2(0,0)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        memset(board, -1, sizeof(board));
        memset(cache, -1, sizeof(cache));
    }
}