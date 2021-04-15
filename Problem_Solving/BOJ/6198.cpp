#include <bits/stdc++.h>
#define bb ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl '\n'
using namespace std;

stack<int> s;
long long c, result;

int main(){
    bb;
    cin >> c;
    while(c--){
        int num; cin >> num;
        if(s.size() == 0) s.push(num);

        else if(s.top() > num){
            result += s.size(); s.push(num); 
        }
        else if(s.top() <= num){
            while(!s.empty()){
                if(s.top() <= num) s.pop();
                else break;
            }
            result += s.size(); s.push(num);
        }
    }

    cout << result << endl;
}