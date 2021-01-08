#include <bits/stdc++.h>
#define SIZE 10
using namespace std;

int c, n, pairs;
bool areFriends[SIZE][SIZE];

int countPairs(bool isPaired[SIZE]){
    int firstFree = -1;
    for(int i=0; i<n; ++i) {
        if(!isPaired[i]){
            firstFree = i;
            break;
        }
    }
    if(firstFree == -1) return 1;
    int ret = 0;
    for(int i=firstFree+1; i<n; ++i)
        if(!isPaired[i] && areFriends[firstFree][i]){
            isPaired[i] = isPaired[firstFree] = true;
            ret += countPairs(isPaired);
            isPaired[i] = isPaired[firstFree] = false;
        }
    
    return ret;
}

int main(){
    cin >> c;
    while(c--){
        cin >> n >> pairs;
        for(int i=0; i<pairs; ++i){
            int x,y;
            cin >> x >> y;
            areFriends[x][y] = true;
            areFriends[y][x] = true;
        }

        bool isPaired[10] = {0,};

        cout << countPairs(isPaired) << endl;

        for(int i=0; i<SIZE; ++i){
            for(int j=0; j<SIZE; ++j){
                areFriends[i][j] = 0;
            }
        }
    }
}