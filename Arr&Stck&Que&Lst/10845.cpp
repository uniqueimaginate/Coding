#include <iostream>
#include <string>

using namespace std;

int queue[10001];
int head;
int tail;

void push(int x){
	queue[tail++] = x;
}

void pop(){
    if(head == tail){
        cout << "-1" << '\n';
    }
    else{
        cout << queue[head++] << '\n';
    }
}

void size(){
    cout << tail - head << '\n';
}

void empty(){
    if(head == tail){
        cout << "1" << '\n';
    }
    else{
        cout << "0" << '\n';
    }
}

void front(){
    if(head == tail){
        cout << "-1" << '\n';
    }
    else{
        cout << queue[head] << '\n';
    }
}

void back(){
    if(head == tail){
        cout << "-1" << '\n';
    }
    else{
        cout << queue[tail-1] << '\n';
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    string str;
    cin >> count;
    for(int i=0; i<count; i++){
        cin >> str;
        if(str == "push"){
            int temp;
            cin >> temp;
            push(temp);
        }
        else if(str == "pop"){
            pop();
        }
        else if(str == "front"){
            front();
        }
        else if(str == "back"){
            back();
        }
        else if(str == "empty"){
            empty();
        }
        else{
            size();
        }
    }
    return 0;
}
