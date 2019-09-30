#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    int b;
    cin >> a >> b;

    for(int i=1; i<=a; i++) q.push(i);
    cout << '<';
    for(int i=0; i<a; i++){
        for(int j=0; j<b-1; j++){
            q.push(q.front());
            q.pop();
        }
        if(i == a-1){
            cout << q.front() << '>' << '\n';
        }
        else{
            cout << q.front() << ", ";
            q.pop();
        }
    }
    return 0;
}