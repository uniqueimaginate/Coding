#include <bits/stdc++.h>

using namespace std;

int arr[129][129];

int blue;
int white;

void solve(int x, int y, int num){
    int tempblue = 0, tempwhite = 0;
    for(int i=x; i<x+num; ++i){
        for(int j=y; j<y+num; ++j){
            if(arr[i][j] == 1) ++tempblue;
            else ++tempwhite;
        }
    }

    if(tempblue == num * num){++blue;return;}
    if(tempwhite == num * num){++white;return;}

    solve(x, y, num/2);
    solve(x + num/2, y, num/2);
    solve(x, y + num/2, num/2);
    solve(x + num/2, y + num/2, num/2);
}

int main(){

    int num; cin >> num;
    for(int i=0; i<num; ++i){
        for(int j=0; j<num; ++j){
            cin >> arr[i][j];
        }
    }

    solve(0, 0, num);
    cout << white << endl;
    cout << blue << endl;

}