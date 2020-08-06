#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define endl '\n'

using namespace std;

int maxCase;
int C;

int check[200];

int arr[60];
int num;

void choose2(int start, int cnt, int sum){
    if(cnt == 2){
        check[sum]++;
        maxCase = max(check[sum], maxCase);
    }

    for(int i=start; i<num; ++i){
        choose2(i+1, cnt+1, sum + arr[i]);
    }
}

int main(){
    cin >> C;
    while(C--){
        cin >> num;
        for(int i=0; i<num; ++i){
            cin >> arr[i];
        }
        choose2(0,0,0);
        cout << maxCase << endl;
        
        memset(arr, 0, sizeof(arr));
        memset(check, 0, sizeof(check));
        maxCase = 0;
    }
}