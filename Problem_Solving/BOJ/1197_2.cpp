#include <iostream>
#include <queue>
#include <utility>
#define MAX_SIZE 10001
#define INF 1000001

using namespace std;

int V, E;
bool visited[MAX_SIZE];
int Vertex[MAX_SIZE];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector< pair< int, int > > graph[MAX_SIZE];
    priority_queue< pair< int, int >, vector< pair<int, int> > , greater< pair<int, int> > > pq;

    cin >> V >> E;

    for(int i=0; i<MAX_SIZE; i++){
        visited[i] = false;
        Vertex[i] = INF;
    }

    while(E--){
        int v1,v2,w;
        cin >> v1 >> v2 >> w;
        graph[v1].push_back(make_pair(v2,w));
        graph[v2].push_back(make_pair(v1,w));
    }

    Vertex[1] = 0;
    pq.push(make_pair(0, 1));
    while(!pq.empty()){
        int cost = pq.top().first;
        int next = pq.top().second;
        visited[next] = true;
        pq.pop();
        for(int i=0; i<graph[next].size(); i++){
            int v2 = graph[next].at(i).first;
            int weight = graph[next].at(i).second;

            if(weight < Vertex[v2] && !visited[v2]){
                Vertex[v2] = weight;
                pq.push(make_pair(weight, v2));
            }
        }
    }

    int total = 0;
    for(int i=1; i<=V; i++){
        total += Vertex[i];
    }
    cout << total << '\n';
    return 0;
}