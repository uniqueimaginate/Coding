#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_SIZE 10001

using namespace std;

int V,E;
int root[MAX_SIZE];

int find(int x){
    if(root[x] == x)
        return x;
    else{
        return root[x] = find(root[x]);
    }
}

void uni(int x, int y){
    x = find(x);
    y = find(y);

    root[y] = x;
}



class Graph{
    public:
        int v1;
        int v2;
        int weight;
    public:
        
        Graph(int _v1, int _v2, int _w) : v1(_v1), v2(_v2), weight(_w)
        {}
        
        bool operator <(const Graph &graph) const {
            return this->weight < graph.weight;
        }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<Graph> vec;

    cin >> V >> E;

    for(int i=0; i<MAX_SIZE; i++){
        root[i] = i;
    }

    while(E--){
        int temp_v1, temp_v2, temp_w;
        cin >> temp_v1 >> temp_v2 >> temp_w;
        vec.push_back(Graph(temp_v1, temp_v2, temp_w));
    }

    sort(vec.begin(), vec.end());
    int total = 0;
    for(int i=0; i<vec.size(); i++){
        int num1 = vec[i].v1;
        int num2 = vec[i].v2;
        if(find(num1) != find(num2)){
            uni(num1, num2);
            total += vec[i].weight;
        }
    }
    cout << total <<'\n';
    return 0;
}