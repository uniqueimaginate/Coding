#include <iostream>
#include <queue>
#define SIZE 52;
using namespace std;

int mx[4] = {0,0,1,-1};
int my[4] = {-1,1,0,0};

int N;
int arr[52][52];
int check[52][52];
int ct;

void bfs(int row, int col, int num){
    queue< pair <int, int> > q;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(arr[i][j] == 1 && check[i][j] == 0){
                ct++;
                q.push(make_pair(i,j));
                check[i][j] = 1;
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int k=0; k<4; k++){
                        int _mx = x+mx[k];
                        int _my = y+my[k];
                        if(0 <= _mx  && _mx < row && 0 <= _my && _my < col){
                            if(arr[_mx][_my] == 1 && check[_mx][_my] == 0){
                                q.push(make_pair(_mx, _my));
                                check[_mx][_my] = 1;
                            }
                        }
                    }

                }
            }
            check[i][j] = 1;
        }
    }
    cout << ct << '\n';
    ct = 0;
    for(int i=0; i<52; i++){
        for(int j=0; j<52; j++){
            arr[i][j] = 0;
            check[i][j] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    while(N--){
        int row, col, num;
        cin >> row >> col >> num;
        // initialize
        while(num--){
            int x, y;
            cin >> x >> y;
            arr[x][y] = 1;
        }
        bfs(row, col, num);
    }
    return 0;
}