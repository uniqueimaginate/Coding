#include <bits/stdc++.h>

using namespace std;
int N;

vector<long long> vec;

void dfs(long long num, int cnt){
    if(cnt == 10)return
    vec.push_back(num);

    for(int i=0; i<10; ++i){
        if(num % 10 > i) dfs(num * 10 + i, cnt + 1);
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;

    for(int i=0; i<10; i++){
        dfs(i,0);
    }

    sort(vec.begin(), vec.end());


    long long answer = vec.size() > N ? vec[N] : -1;

    cout << answer << "\n";

    return 0;
}