#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl '\n'
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int C;

int main(){
    bb;
    cin >> C;
    while(C--){
        int temp; cin >> temp;
        if(temp == 0){
            if(pq.empty()) cout << "0" << endl;
            else{
                cout << pq.top() << endl;
                pq.pop();
            }
            
        }
        else{
            pq.push(temp);
        }
    }
    return 0;
}