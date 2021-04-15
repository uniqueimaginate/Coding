#include <bits/stdc++.h>

using namespace std;

int C, n;
int triangle[100][100];
int cache[100][100];

// brute force
int sumTriangle1(int y, int x, int sum){
    if(y == n-1) return sum+triangle[y][x];
    return max(sumTriangle1(y+1, x, sum + triangle[y][x]), sumTriangle1(y+1, x+1, sum + triangle[y][x]));
}

// memoization
int sumTriangle2(int y, int x){
    if(y == n-1) return triangle[y][x];
    int& ret = cache[y][x];
    if(ret != -1) return ret;
    return ret = max(sumTriangle2(y+1, x), sumTriangle2(y+1, x+1)) + triangle[y][x]; 
}


int main(){
    memset(cache, -1, sizeof(cache));
    cin >> C;
    while(C--){
        cin >> n;
        for(int i=0; i<n; ++i){
            for(int j=0; j<i+1; ++j){
                cin >> triangle[i][j];
            }
        }
        cout << sumTriangle2(0,0) << endl;
        memset(triangle, 0, sizeof(triangle));
        memset(cache, -1, sizeof(cache));

    }
}