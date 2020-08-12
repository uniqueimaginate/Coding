#include <bits/stdc++.h>

using namespace std;

vector<char> result;
stack<char> stck;

int makePriority(char c){
    if(c == '*' || c == '/') return 3;
    else if(c == '+' || c == '-') return 2;
    else if(c == '(') return 1;
}

void solve(char c){
    cout << c << endl;
    if('A' <= c && c <= 'Z') result.push_back(c);

    if(c == '(') stck.push(c);
    else if(c == ')'){
        while(1){
            if(stck.top() == '('){
                stck.pop(); break;
            }
            result.push_back(stck.top()); stck.pop();
        }
    }
    int priority = makePriority(c);
    if(priority == 3){
        if(stck.empty()) {stck.push(c);return;}
        while(1){
            if(makePriority(stck.top()) < 3) {stck.push(c);break;}
            result.push_back(stck.top()); stck.pop();
            if(stck.empty()){
                stck.push(c); break;
            }

        }
    } else if(priority == 2){
        if(stck.empty()) {stck.push(c);return;}
        while(1){
            if(makePriority(stck.top()) < 2) {stck.push(c);break;}
            result.push_back(stck.top()); stck.pop();
            if(stck.empty()){stck.push(c); break;}   
        }
    }
}

int main(){
    string inOrder;
    cin >> inOrder;

    for(int i=0; i < inOrder.size(); ++i){
        solve(inOrder[i]);
    }

    while(!stck.empty()){
        result.push_back(stck.top());
        stck.pop();
    }
    for(auto c : result){
        cout << c;
    }
    cout << endl;
}