#include <iostream>
#include <string>

using namespace std;

int deque[20010];
int head = 10000;
int tail = 10000;;

void push_back(int val){
    deque[tail++] = val;
}

void push_front(int val){
    deque[--head] = val;
}

void pop_back(){
    if(head == tail){
        cout << "-1" << '\n';
    }
    else{
        cout << deque[--tail] << '\n';
    }

}

void pop_front(){
    if(head == tail){
        cout << "-1" << '\n';
    }
    else{
        cout << deque[head++] << '\n';
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
    if(head == tail)
        cout << "-1" << '\n';
    else
    {
        cout << deque[head] << '\n';
    }
}

void back(){
    if(head == tail)
        cout << "-1" << '\n';
    else
        cout << deque[tail-1] << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int count;
    string str;

    cin >> count;

    for(int i=0; i<count; i++){
        cin >> str;
        if(str == "push_front"){
            int temp;
            cin >> temp;
            push_front(temp);
        }
        else if(str == "push_back"){
            int temp;
            cin >> temp;
            push_back(temp);
        }
        else if(str == "pop_back"){
            pop_back();
        }
        else if(str == "pop_front"){
            pop_front();
        }
        else if(str == "size"){
            size();
        }
        else if(str == "empty"){
            empty();
        }
        else if(str == "front"){
            front();
        }
        else{
            back();
        }
    }

    return 0;
}