#include <bits/stdc++.h>

using namespace std;

bool isBalanced(const string& str){
    stack<char> brackets;
    const string open = "[(";
    const string close = "])";

    for(int i=0; i<str.size(); ++i){
        if(open.find(str[i])+1){
            brackets.push(str[i]);
        } else if(close.find(str[i])+1){
            if(brackets.empty()) return false;
            if(brackets.top() == open[close.find(str[i])]){
                brackets.pop();
            }
            else return false;
        }
        else continue;
    }

    if(brackets.empty()) return true;
    else return false;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1){
        string str;
        getline(cin, str);
        if(str[0] == '.') break;
        isBalanced(str) ? cout << "yes" << endl : cout << "no" << endl;
    }
}