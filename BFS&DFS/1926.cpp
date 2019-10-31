#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int main(){
    int row, col;
    cin >> row >> col;
    queue< pair< int, int> > q;

    int **arr = new int*[row];
    int **check = new int*[row];

    for(int i=0; i<row; i++){
        arr[i] = new int[col];
        check[i] = new int[col];
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
            check[i][j] = 0;
        }
    }

    int max = 0;
    int count = 0;
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(check[i][j] == 0){

                if(arr[i][j] == 0){
                    check[i][j] = 1;
                    continue;
                }
                else if(arr[i][j] == 1){
                    check[i][j] = 1;
                    count++;
                    int area = 1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        
                        q.pop();
                        for(int k=0; k<4; k++){
                            int tempX = x + dx[k];
                            int tempY = y + dy[k];
                            if(tempX >= 0 && tempX < row && tempY >=0 && tempY < col){
                                if(arr[tempX][tempY] == 1 && check[tempX][tempY] == 0){
                                    q.push(make_pair(tempX, tempY));
                                    check[tempX][tempY] = 1;
                                    area++;
                                }
                            }
                        }
                    }
                    if(area > max){
                        max = area;
                    }
                }
            }
            else{
                continue;
            }
        }
    }
    cout << count << endl;
    cout << max << endl;
    return 0;
}