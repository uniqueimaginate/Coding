#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;

struct tomato{
    int x;
    int y;
    int z;
};

const int dx[] = {0,0,1,-1,0,0}, dy[] = {1,-1,0,0,0,0}, dz[] = {0,0,0,0,1,-1};

int arr[101][101][101];

queue<tomato> q;

int m, n, h;

void bfs(){
    while(!q.empty()){
        int x = q.front().x, y = q.front().y, z = q.front().z;
        q.pop();

        for(int i=0; i<6; ++i){
            int nx = x + dx[i], ny = y + dy[i], nz = z + dz[i];
            if(nx < 0 || nx >= m || ny < 0 || ny >= n || nz < 0 || nz >=h) continue;
            if(arr[nz][ny][nx]) continue;
            arr[nz][ny][nx] = arr[z][y][x] + 1;
            q.push({nx, ny, nz});
        }

    }

}

int main(){
    bb;
    cin >> m >> n >> h;

    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                cin >> arr[i][j][k];
                if(arr[i][j][k] == 1){
                    q.push({k, j, i});
                }
            }
        }
    }

    bfs();


    int result = 0;
    for(int i=0; i<h; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<m; ++k){
                if(arr[i][j][k] == 0){
                    cout << "-1" << endl; return 0;
                }
                result = max(result, arr[i][j][k]);
            }
        }
    }

    cout << result-1 << endl;


}