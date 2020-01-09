#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int arr[1010][1010];
int checkBFS[1010];
int checkDFS[1010];

typedef struct _struct{
    int src;
    int dest;
} E;

void dfs(const int _start, const int _vertex){
    stack<E> s;
    int start = _start;
    E eg1 = {0, start};
    s.push(eg1);

    while(!s.empty()){
        E temp = s.top();
        s.pop();
        if(checkDFS[temp.dest] == 1)
            continue;
        cout << temp.dest << " ";
        checkDFS[temp.dest] = 1;

        for(int i=_vertex; i>=1; i--){
            if(arr[temp.dest][i] == 1 && checkDFS[i] != 1){
                E eg;
                eg.src = temp.dest;
                eg.dest = i;
                s.push(eg);
            }
        }
    }
    cout << '\n';

}
void bfs(const int _start, const int _vertex){
    queue<E> q;
    int start = _start;
    E eg1 = {0, start};
    q.push(eg1);

    while(!q.empty()){
        E temp = q.front();
        q.pop();
        if(checkBFS[temp.dest] == 1)
            continue;
        cout << temp.dest << " ";
        checkBFS[temp.dest] = 1;

        for(int i=1; i<= _vertex; i++){
            if(arr[temp.dest][i] == 1 && checkBFS[i] != 1){
                E eg;
                eg.src = temp.dest;
                eg.dest = i;
                q.push(eg);
            }
        }
    }
    cout << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int vertex;
    int edge;
    int start;

    cin >> vertex >> edge >> start;

    for(int i=0; i<edge; i++){
        int x, y;
        cin >> x >> y;
        arr[x][y] = 1;
        arr[y][x] = 1;
    }


    dfs(start, vertex);
    bfs(start, vertex);

    return 0;
}