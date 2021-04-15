#include <bits/stdc++.h>

using namespace std;
char open[3] = {'(', '{', '['};
char close[3] = {')', '}', ']'};

int C;

bool matchBrackets(const string& str){
    stack<char> brackets;
    for(int i=0; i<str.size(); ++i){
        if(brackets.empty()){
            brackets.push(str[i]);
        }
        else{
            for(int j=0; j<3; ++j){
                if(str[i] == open[j]){
                    brackets.push(str[i]);
                    break;
                }
                else if(str[i] == close[j]){
                    if(brackets.top() == open[j]){
                        brackets.pop();
                    }
                    else{
                        return false;
                    }
                }
            }

        }
    }

    if(!brackets.empty()){
        return false;
    }

    return true;
}

int main(){
    cin >> C;
    while(C--){
        string str;
        cin >> str;

        if(matchBrackets(str)){
            cout << "YES" << endl;
        } else{
            cout << "NO" << endl;
        }
    }
}