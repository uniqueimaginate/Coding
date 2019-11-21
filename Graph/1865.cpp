#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 987654321
using namespace std;
int edge[503][503];
int dist[503]; 

#define X first
#define Y second

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int T;
    cin >> T;
	
	while (T--) {
		int N, M, W;
		cin >> N >> M >> W;
		for (int i = 1; i <= N; i++) {
			dist[i] = MAX; // dist initialization
			for (int j = 1; j <= N; j++)
				edge[i][j] = MAX; // edge initialization
		}

		dist[1] = 0;
		while (M--) {
			int S, E, T;
			cin >> S >> E >> T;
			edge[S][E] = min(edge[S][E], T);
			edge[E][S] = min(edge[E][S], T);
		}

		while (W--) {
			int S, E, T;
			cin >> S >> E >> T;
			edge[S][E] = min(edge[S][E], -T);
		}
		vector< pair < int, int > > adj[503]; // {index, dist}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (edge[i][j] < MAX)
					adj[i].push_back(make_pair(j, edge[i][j]));
			}
		}
		bool negCycle = false;
		for (int edge_num = 1; edge_num <= N; edge_num++) {
			for (int st = 1; st <= N; st++) {
				if (dist[st] == MAX)
					continue; // auto near : adj[st]
				for (int in = 0; in < adj[st].size(); in++) {
					if (dist[st] + adj[st][in].Y < dist[adj[st][in].X]) {
						dist[adj[st][in].X] = dist[st] + adj[st][in].Y;
						if (edge_num == N) // negative cycle이 존재
							negCycle = true;
					}
				}
			}
		}
		if (dist[1] < 0 || negCycle)
			cout << "YES\n";
		else
			cout << "NO\n";		
	}
}