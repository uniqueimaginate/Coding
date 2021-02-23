#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    stack<char> s;

    cin >> str;
    int total = 0;
    int temp = 0;


    for(int i=0; i<str.size(); i++){
        if(str[i] == '(' || str[i] == '['){
            string sstr(str[i]);
            s.push(sstr);
        }

        if(str[i] == ')'){
            if(str[i-1] != '('){
                while(s.top() != '('){
                    string ss = s.top();
                    s.pop();
                    temp += atoi(ss.c_str());
                }
                s.push(to_string(temp));
                temp = 0;
            }
        }
        if(str[i] == ']'){
            if(str[i-1] != '['){
                while(s.top() != '['){
                    string ss = to_string(s.top());
                    s.pop();
                    temp += atoi(ss.c_str());
                }
                s.push(to_string(temp));
                temp = 0;
            }
        }
        if(str[i] == ')'){
            if(str[i-1] == '('){
                s.pop();
                s.push('2');
            }
        }
        else{
            if(str[i-1] == '['){
                s.pop();
                s.push('3');
            }
        }
    }

    return 0;
}