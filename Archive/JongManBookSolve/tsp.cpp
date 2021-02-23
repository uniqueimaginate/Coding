// I will write only functional part not the whole code.

#include <bits/stdc++.h>

#define SIZE 10

using namespace std;

const int INF = numeric_limits<int>::max();
int n; 
double dist[SIZE][SIZE];

double shortestPath(vector<int>&path, vector<bool>& visited, double currentLength){
    if(path.size() == n) return currentLength + dist[path[0]][path.back()];

    double ret = INF;

    for(int next = 0; next < n; ++next){
        if(visited[next]) continue;
        int here = path.back();
        path.push_back(next);
        visited[here] = true;
        double cand = shortestPath(path, visited, currentLength + dist[here][next]);

        ret = min(ret, cand);
        visited[here] = false;
        path.pop_back();
    }

    return ret;
}
