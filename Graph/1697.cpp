#include <iostream>
#include <queue>
#define SIZE 100001
using namespace std;
int check[SIZE];
queue<int> q;
int N,K;

void bfs(){
    q.push(N);
    check[N] = 1;
    while(!q.empty()){
        int pos = q.front();
        q.pop();
        if(pos == K){ cout<< check[pos]-1 << endl; break;}
        
        if(2 * pos <= 100000 && check[2*pos] == 0){
            q.push(2 * pos);
            check[2 * pos] = check[pos] + 1;
        }
        if(pos+1 <= 100000 && check[pos+1] == 0 ){
            q.push(pos+1);
            check[pos+1] = check[pos] + 1;
        }
        if(check[pos-1] == 0 && pos-1 >= 0){
            q.push(pos-1);
            check[pos-1] = check[pos] + 1;
        }   
    }
}

int main(){
    cin >> N >> K;
    if(N >= K){
        cout << N-K << endl;
        return 0;
    }
    bfs();
    return 0;
}