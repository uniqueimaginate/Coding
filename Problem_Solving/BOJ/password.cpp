// SW expert Academy
#include <iostream>
#include <queue>

using namespace std;
queue<int> q;

void func(){
    int decre = 1;
    while(true){
        if(q.front() - decre <= 0){
            q.pop();
            q.push(0);
            return;
        }
        int front = q.front();
        q.pop();
        q.push(front - decre);
        decre++;
        if(decre == 6){
            decre = 1;
        }
    }
}

void printQ(int n){
    cout << "#" << n << " ";
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    int n;
    while(cin >> n){
        for(int i=0; i<8; i++){
            int temp;
            cin >> temp;
            q.push(temp);
        }
        func();
        printQ(n);
        cout << endl;
    }
    return 0;
}
