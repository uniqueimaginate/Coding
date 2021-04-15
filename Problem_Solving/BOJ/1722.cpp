#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;

vector<int> vec;
long long factorial[21];
int N, K;
long long pos;

vector<int> result;
int j;

long long result2;

void fact(){
    factorial[0] = 1;
    factorial[1] = 1;
    for(int i=2; i<22; ++i){
        factorial[i] = i * factorial[i-1];
    }
}

void solve(long long pos){
    int i = 1;
    while(N-i+1){
        long long q = pos / factorial[N-i];
        if(q != 0){
            pos -= (q * factorial[N-i]);
        }
        result.push_back(vec[q]);
        vec.erase(vec.begin() + q);
        ++i;
    }

    for(auto i : result){
        cout << i << " ";
    }
    cout << endl;
}

void solve2(int temp){

    for(int i=0; i<vec.size(); ++i){
        if(temp == vec[i]){
            result2 += (factorial[N-j] * i);
            int a = factorial[N-j] * i;
            vec.erase(vec.begin() + i);
            ++j;
        }
    }
   
}

int main(){
    bb;
    fact();

    cin >> N;
    for(int i=1; i<=N; ++i){
        vec.push_back(i);
    }
    
    cin >> K;
    j = 1;
    if(K == 1){
        cin >> pos;
        solve(pos-1);
    }
    else{
        for(int i=0; i<N; i++){
            int temp; cin >> temp;
            solve2(temp);
        }
        cout << result2+1 << endl;
    }
}   