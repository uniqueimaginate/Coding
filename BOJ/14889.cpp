#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
#define MAX 987654321
using namespace std;

int arr[21][21];
int people[21];
int tmp[21];
int check[21];
int C;

int minN = MAX;

void solve(int start, int cnt){
    if(cnt == C/2){
        vector<int> teamA, teamB;
        memset(check, 0, sizeof(check));
        for(int i=0; i<C/2; ++i){
            teamA.push_back(tmp[i]);
            check[tmp[i]] = 1;
        }
        for(int i=1; i<=C; i++){
            if(check[i] == 0){
                teamB.push_back(i);
            }
        }
        int aScore = 0, bScore = 0;
        for(int i=0; i<teamA.size(); ++i){
            for(int j = i + 1; j<teamA.size(); ++j){
                aScore += arr[teamA[i]][teamA[j]];
                aScore += arr[teamA[j]][teamA[i]];
            }
        }

        for(int i=0; i<teamB.size(); ++i){
            for(int j = i+1; j<teamB.size(); ++j){
                bScore += arr[teamB[i]][teamB[j]];
                bScore += arr[teamB[j]][teamB[i]];
            }
        }

        int temp = abs(aScore - bScore);
        if(temp < minN) minN = temp;

        return;
    }

    for(int i=start; i<=C; ++i){
        tmp[cnt] = people[i];
        solve(i + 1, cnt + 1);
    }
    
}

int main(){
    bb;
    cin >> C;
    for(int i=1; i<=C; ++i){
        for(int j=1; j<=C; ++j){
            cin >> arr[i][j];
        }
    }

    for(int i=0; i<21; ++i){
        people[i] = i; 
    }

    solve(1, 0);
    cout << minN << endl;
}