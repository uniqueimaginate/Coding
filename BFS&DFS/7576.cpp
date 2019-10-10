#include <iostream>
#include <queue>

using namespace std;

typedef struct _struct{
    int x;
    int y;
    int length;
} Vertex;

int arr[1010][1010];
int check[1010][1010];
queue<Vertex> q;

void bfs(const int unr, const int row, const int col){
    int count = 0;
    int max = 0;
    while(!q.empty()){
        Vertex t = q.front();
        q.pop();
        check[t.x][t.y] = 1;
        if(t.length > max)
            max = t.length;
        if(t.x + 1 < row && arr[t.x+1][t.y] == 0 && check[t.x+1][t.y] == 0){
            Vertex temp = {t.x+1, t.y, t.length + 1};
            check[t.x+1][t.y] = 1;
            q.push(temp);
            count++;
            if(temp.length > max)
                max = temp.length;
        }
        if(t.x-1 >= 0 && arr[t.x-1][t.y] == 0 && check[t.x-1][t.y] == 0){
            Vertex temp = {t.x-1, t.y, t.length + 1};
            check[t.x-1][t.y] = 1;
            q.push(temp);
            count++;
            if(temp.length > max)
                max = temp.length;
            // cout << temp.x << temp.y << endl;
        }
        if(t.y + 1 < col && arr[t.x][t.y + 1] == 0 && check[t.x][t.y + 1] == 0){
            Vertex temp = {t.x, t.y + 1, t.length + 1};
            check[t.x][t.y + 1] = 1;
            q.push(temp);
            count++;
            if(temp.length > max)
                max = temp.length;
        }
        if(t.y - 1 >= 0 && arr[t.x][t.y - 1] == 0 && check[t.x][t.y - 1] == 0){
            Vertex temp = {t.x, t.y - 1, t.length + 1};
            check[t.x][t.y - 1] = 1;
            q.push(temp);
            count++;
            if(temp.length > max)
                max = temp.length;
        }
    }

    if(count != unr){
        cout << "-1" << '\n';
    }
    else{
        cout << max << '\n';
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int row, col;
    cin >> col >> row;

    int unr=0;
    int ra=0;
    int no=0;

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 0)
                unr++;
            if(arr[i][j] == 1){
                Vertex temp = {i,j,0};
                q.push(temp);
                ra++;
            }
            else
            {
                no++;
            }
            
        }
    }
    if(ra == row*col){
        cout << "0" << '\n';
        return 0;
    }
    if(no == row*col){
        cout << "-1" << '\n';
        return 0;
    }

    bfs(unr, row, col);
    return 0;
}