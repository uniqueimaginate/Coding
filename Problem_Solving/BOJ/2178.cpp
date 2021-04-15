#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int arr[100][100];
int check[100][100];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

typedef struct _pair{
    int x;
    int y;
}Pair;

void bfs(const int row, const int col){
    queue<Pair> q;
    Pair a = {0,0};
    check[0][0] = 1;
    q.push(a);
    while(!q.empty()){
        Pair temp = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = temp.x + dx[i];
            int ny = temp.y + dy[i];
            if(0 <= nx && nx < row && 0 <= ny && ny < col){
                if(check[nx][ny] == 0 && arr[nx][ny] == 1){
                    Pair t = {nx, ny};
                    q.push(t);
                    check[nx][ny] = check[temp.x][temp.y]+1;
                }
            }
        }
    }
}

int main(){
    int N, M;
    char c;
    scanf("%d %d\n", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%c", &c);
            c = c - '0';
            arr[i][j] = (int)c;
        }
        scanf("%c", &c);
    }

    bfs(N, M);   
    cout << check[N-1][M-1] << endl; 
}