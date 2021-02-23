#include <iostream>
#include <cstdio>
#include <string>
#define SIZE 50

using namespace std;

char case1[8][8]=   {{'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'}};

char case2[8][8]=   {{'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'},
                     {'B','W','B','W','B','W','B','W'},
                     {'W','B','W','B','W','B','W','B'}};

char arr[SIZE][SIZE];

int minNum = 987654321;

int checkBox(int posI, int posJ){
    int case1num = 0;
    int case2num = 0;
    
    for(int i=0; i<8; ++i){
        for(int j=0; j<8; ++j){
            if(case1[i][j] != arr[i+posI][j+posJ])
                case1num++;
            if(case2[i][j] != arr[i+posI][j+posJ])
                case2num++;
        }
    }

    if(case1num > case2num) return case2num;
    else return case1num;
}

int main(){
    int N,M;
    scanf("%d %d\n", &N, &M);

    for(int i=0; i<N; ++i){
        string str;
        cin >> str;
        for(int j=0; j<M; ++j){
            arr[i][j] = str[j];
        }
    }

    for(int i=0; i<=N-8; ++i){
        for(int j=0; j<=M-8; ++j){
            int num = checkBox(i,j);
            if(num < minNum)
                minNum = num;
        }
    }
    
    cout << minNum << endl;
}