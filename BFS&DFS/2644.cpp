#include <iostream>
#include <queue>
using namespace std;

int arr[101][101];
int check[101];

typedef struct _struct{
    int v;
    int length;
} Vertex;

void bfs(const int start, const int dest, const int num){
    int result=0;
    queue<Vertex> q;
    Vertex st = {start, 0};
    q.push(st);

    while(!q.empty()){
        Vertex temp = q.front();
        q.pop();

        for(int i=1; i<=num; i++){
            if(arr[temp.v][i] == 1 && check[i] == 0){
                if(i == dest){
                    cout << temp.length + 1 << '\n';
                    return;
                }
                Vertex t = {i, temp.length + 1};
                q.push(t);
                check[temp.v] = 1;
            }
        }
    }
    cout << "-1" << '\n';
    return;
}

int main(){
    int num;
    cin >> num;
    int s, d;
    cin >> s >> d;
    int count;
    cin >> count;

    for(int i=0; i<count; i++){
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    bfs(s, d, num);
    return 0;
}