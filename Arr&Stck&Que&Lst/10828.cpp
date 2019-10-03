#include <iostream>
#include <string>

using namespace std;

int stack[10000];
int pos;

void push(int val){
    stack[pos] = val;
    pos++;
}

void empty(){
    if(pos == 0){
        cout << "1" << '\n';
    }
    else{
        cout << "0" << '\n';
    }
}

void top(){
    if(pos != 0){
        cout << stack[pos-1] <<'\n';
    }
    else
        cout << -1 << '\n';
}

void size(){
    cout << pos << '\n';
}

void pop(){
    if(pos != 0){
        int temp = stack[--pos];
        cout << temp << '\n';
        
    }
    else
        cout << -1 << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a;
    string str;
    cin >> a;

    for(int i = 0; i<a; i++){
        cin >> str;
        if(str == "push"){
            int temp;
            cin >> temp;
            push(temp);
        }
        else if(str == "top")
        {
            top();
        }
        else if(str == "empty"){
            empty();
        }
        else if(str == "pop"){
            pop();
        }
        else
        {
            size();
        }
    }
    return 0;
}