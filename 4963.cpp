#include <iostream>
#include <queue>
using namespace std;

typedef struct _struct{
    int x;
    int y;
} Pos;

int arr[50][50];
int check[50][50];

void bfs(const int row, const int col){
    int k = 0;
    queue<Pos> q;
    for(int i =0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                k++;
                Pos temp = {i,j};
                q.push(temp);
                while(!q.empty()){
                    Pos p = q.front();
                    q.pop();
                    check[p.x][p.y]=1;

                    if(p.y + 1 < col && (arr[p.x][p.y+1] == 1) && check[p.x][p.y+1] == 0){
                        Pos t = {p.x, p.y + 1};
                        check[p.x][p.y+1] = 1;
                        q.push(t);
                    }
                    if(p.y - 1 >= 0 && (arr[p.x][p.y-1] == 1) && check[p.x][p.y-1] == 0){
                        Pos t = {p.x, p.y - 1};
                        check[p.x][p.y-1] = 1;
                        q.push(t);
                    }
                    if(p.x + 1 < row && (arr[p.x+1][p.y] == 1) && check[p.x+1][p.y] == 0){
                        Pos t = {p.x + 1, p.y};
                        check[p.x + 1][p.y] = 1;
                        q.push(t);
                    }
                    if(p.x - 1 >= 0 && (arr[p.x-1][p.y] == 1) && check[p.x-1][p.y] == 0){
                        Pos t = {p.x - 1, p.y};
                        check[p.x - 1][p.y] = 1;
                        q.push(t);
                    }
                    if(p.x + 1 < row && p.y + 1 < col && (arr[p.x+1][p.y+1] == 1) && check[p.x+1][p.y+1] == 0){
                        Pos t = {p.x + 1, p.y + 1};
                        check[p.x + 1][p.y + 1] = 1;
                        q.push(t);
                    }
                    if(p.x - 1 >= 0 && p.y - 1 >= 0 && (arr[p.x-1][p.y-1] == 1) && check[p.x-1][p.y-1] == 0){
                        Pos t = {p.x - 1, p.y - 1};
                        check[p.x - 1][p.y - 1] = 1;
                        q.push(t);
                    }
                    if(p.x + 1 < row && p.y - 1 >= 0 && (arr[p.x+1][p.y-1] == 1) && check[p.x+1][p.y-1] == 0){
                        Pos t = {p.x + 1, p.y - 1};
                        check[p.x + 1][p.y - 1] = 1;
                        q.push(t);
                    }
                    if(p.x - 1 >= 0 && p.y + 1 < col && (arr[p.x-1][p.y+1] == 1) && check[p.x-1][p.y+1] == 0){
                        Pos t = {p.x - 1, p.y + 1};
                        check[p.x - 1][p.y + 1] = 1;
                        q.push(t);
                    }                        
                }
            }
            else{
                continue;
            }
        }
    }
    cout << k << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true){
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0)
            break;
        for(int i=0; i<b; i++){
            for(int j=0; j<a; j++){
                cin >> arr[i][j];
                check[i][j] = 0;
            }
        }
        bfs(b, a);
    }
    return 0;
}
