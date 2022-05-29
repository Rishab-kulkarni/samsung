
// This algorithm fixes one of the node as the source node and finds shortest path 
// from source to all other nodes in the graph.

// Widely used in network routing protocols.

// It uses a data structure for finding shortest path to each of the node in graph from the source node.
// The original algorithm uses min heap O(|V + E|logV) can also be implemented using O(V^2)

/* Algorithm 

1. Mark all nodes unvisited. Create a set of all unvisited nodes called unvisited set.
2. Maintain a dist array and mark distance to every other node as infinity.
3. Maintain a priority queue of pairs {dist, index} which tell you which node to visit based on sort min value.
4. Insert the source node along with distance dist = 0, index = 0 {0, 0} while pq is not empty pulling out the next promising node. (dist, index).
5. Iterate all over edges outwards from the current node and relax edge, appending a new (dist, index) pair into the pq.
6. Continue the above until all nodes are processed.
*/

/*
	All the edges should have positive weights, because once a node is marked visited 
	Only that cost assigned is the min possible weight for that particular node.

	The main assertion is that once a node is marked visited, the current distance 
	d[v] is the shortest and will no longer change.
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
	int n, m; cin >> n >> m;

	vector<vector<pair<ll,ll>>> adj(n);
	for(int i = 0 ; i < m ; ++i) {
		ll a, b, w; cin >> a >> b >> w;
		--a, --b;
		adj[a].push_back({b, w});
		adj[b].push_back({a, w});
	}

	const ll INF = LLONG_MAX;
	vector<ll> dist(n, INF), p(n, 0);
	vector<bool> vis(n, false);
	

	set<pair<ll,ll>> s;
	s.insert({0, 0});				// (distance, node index)

	dist[0] = 0;

	while( !s.empty() ) {
		ll node = (*s.begin()).second;
		s.erase(s.begin());
		if(vis[node]) continue;
		vis[node] = true;

		for(auto val : adj[node]) {
			ll neighbor = val.first;
			ll cost = val.second;

			if(dist[node] + cost < dist[neighbor]) {
				dist[neighbor] = dist[node] + cost;
				p[neighbor] = node;
				s.insert({dist[neighbor], neighbor});
			}

		}
	}

	if(dist[n - 1] == INF) {
		cout << -1 << '\n'; return;
	} 

	vector<ll> path;
	path.push_back(n - 1);

	int node = n - 1;
	while(true) {
		if(p[node] != 0) {
			path.push_back(p[node]);
			node = p[node];
		}

		else {
			path.push_back(p[node]);
			break;
		}
	}

	reverse(path.begin(), path.end());
	for(int val : path) cout << val + 1<< ' ';
	cout << endl;
}


int main() {

	int t = 1;
	while(t--) solve();
}