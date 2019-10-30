#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    stack<char> s;
    cin >> str;
    
    int num = 0;
    
    for(int i=0; i<str.size(); i++){
        if(str[i] == '('){
            s.push('(');
        }
        else if(str[i] == ')'){
            if(str[i-1] == '('){
                s.pop();
                num += s.size();
            }
            else{
                num++;
                s.pop();
            }
        }
    }
    cout << num << endl;
    return 0;
}