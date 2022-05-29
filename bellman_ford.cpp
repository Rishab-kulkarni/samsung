
// Dijkstra's algorithm doesn't work for negative edges.
// Will end up in an infinite loop if negative edges are present.

// Works for directed graphs.
// If there is a negative cycle, it won't be able to find the shortest path.
// But bellman ford will be able to detect negative cycles in direced graphs.

// If given there is an undirected graph we can convert it into directed graph.
// Use the concept of bidrectional edges.
// If there is a negative edge in the undirected graph bellman ford won't work.

/*

1. Relax the graph N - 1 times i.e., if(dist[u] + cost < dist[v]) dist[v] = dist[u] + cost
2. If we want to detect a negative cycle, relax each edge one more time. If the distance reduces there is a negative cycle.
*/

/*
Why N-1 times ? 
Because the max path length in a directed graph from src to dest can be N-1.
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n, m; cin >> n >> m;
	vector<pair<pair<int,int>,int>> adj;

	for(int i = 0 ; i < m ; ++i) {
		int a,b,w; cin >> a >> b >> w;
		// pair<pair<int,int>,int> x;
		// x = {{a, b}, w};
		// --a, --b;
		adj.push_back({{a, b}, w});
	}

	vector<int> d(n + 1, 1e8);
	d[1] = 0;
	for(int i = 0 ; i < n - 1 ; ++i) {
		for(int j = 0 ; j < m ; ++j) {
			auto node = adj[j];
			int u = node.first.first, v = node.first.second, w = node.second;
			// cout << "u = " << u << ' ' << "v = " << v << ' ' << "w = " << w << endl;
			if(d[u] + w < d[v]) d[v] = d[u] + w;
		}
	}

	// one more iteration here for checking negative cycle.
	for(int j = 0 ; j < m ; ++j) {
		auto node = adj[j];
		int u = node.first.first, v = node.first.second, w = node.second;
		if(d[u] + w < d[v]) {
			cout << "Negative cycle\n"; return;
		}
	}

	for(int i = 1 ; i <= n ; ++i) cout << d[i] << ' ';
	cout << endl;

}

int main() {
	int t = 1;
	while(t--) solve();
}




