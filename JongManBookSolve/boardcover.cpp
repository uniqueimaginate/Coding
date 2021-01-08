#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;

int c;

const int boardType[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, 1}},
    {{0, 0}, {1, 0}, {1,-1}}
};

bool setBoard(vector<vector<int>>& board, int y, int x, int type, int delta){
    bool isCovered = true;

    for(int i=0; i < 3; ++i){
        const int ny = y + boardType[type][i][0];
        const int nx = x + boardType[type][i][1];

        if(ny < 0 || nx < 0 || ny >= board.size() || nx >= board[0].size()) isCovered = false;
        else if((board[ny][nx] += delta) > 1) isCovered = false;
    }

    return isCovered;
}

int countCase(vector<vector<int>> &board){
    int y = -1, x = -1;
    for(int i=0; i<board.size(); ++i){
        for(int j=0; j<board[i].size(); ++j){
            if(board[i][j] == 0){
                y = i;
                x = j;
                break;
            }
        }
        if(y != -1) break;
    }

    if(y == -1) return 1;

    int ret = 0;
    for(int type = 0; type < 4; ++type){
        if(setBoard(board, y, x, type, 1))
            ret += countCase(board);
        setBoard(board, y, x, type, -1);
    }
    return ret;
}

int main(){
    cin >> c;
    while(c--){
        int y, x; cin >> y >> x;
        vector<vector<int>> board(y);
        int count = 0;
        for(int i=0; i<y; ++i){
            string str; cin >> str;
            for(int j=0; j<x; ++j){
                if(str[j] == '#')
                    board[i].push_back(1);
                else
                    board[i].push_back(0);
                if(str[j] == '.') ++count;
            }
        }

        if((count % 3) != 0){
            cout << "0" << endl;
            continue;
        }
        
        cout << countCase(board) << endl;

    }
}

