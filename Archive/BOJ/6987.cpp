#include <bits/stdc++.h>

using namespace std;

int game[6][3];

bool check(){
    return accumulate(&game[0][0], &game[6][3], 0) == 30;
}

bool f(int x, int y, int cnt){
    if(cnt == 15){
        return true;
    }
    int newX, newY;

    if(y == 5){
        newX = x + 1;
        newY = x + 2;
    } else{
        newX = x;
        newY = y + 1;
    }

    bool ret = false;
    
    for(int k=0; k<3; ++k){
        if(game[x][k] > 0 && game[y][2-k] > 0){
            game[x][k]--;
            game[y][2-k]--;
            if(f(newX, newY, cnt+1)) return true;
            game[x][k]++;
            game[y][2-k]++;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0); 
    for(int c=0; c<4; ++c){
        for(int i=0; i<6; ++i){
            for(int j=0; j<3; ++j){
                cin >> game[i][j];
            }
        }

        cout << (check() && f(0,1,0)) << ' ';
    }
    cout << endl;

    
}