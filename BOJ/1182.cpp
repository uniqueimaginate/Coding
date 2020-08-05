#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int N,S;
int arr[21];
int result;

void solve(int start, int sum, int cnt, int num){
    if(cnt == num){
        if(sum == S)++result;
        return;
    }

    for(int i=start; i<N; ++i){
        solve(i+1, sum + arr[i], cnt+1, num);
    }
}

int main(){
    bb;
    cin >> N >> S;

    for(int i=0; i<N; ++i){
        cin >> arr[i];
    }

   for(int i=1; i<=N; ++i){
       solve(0,0,0, i);
   }

   cout << result << endl;
}