
// Topological sort 
// Only possible for directed acyclic graphs.
// linear ordering of vertices such that for any given edge a->b  a appears before b in that linear ordering. 
// layman terms --> for us to reach a point we must compelete all its dependencies then go that point.

#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &topo) {
	vis[curr] = true;
	for(int neighbor : adj[curr]) {
		if (!vis[neighbor]) {
			dfs(neighbor, adj, vis, topo);
		}
	}
	topo.push_back(curr);
}


void kahn_algo(vector<vector<int>> &adj) {
	// create a vector - find indegree of every node
	// find all the nodes with indegree 0 and push them into queue (bfs)

	int n = adj.size();
	vector<int> indegree(n, 0);
	for(int i = 0 ; i < n ; ++i) {
		vector<int> temp = adj[i];
		for(int val : temp) indegree[val]++;
	}

	queue<int> q;
	for(int i = 0 ; i < n ; ++i) {
		if(indegree[i] == 0) q.push(i);
	}

	while( !q.empty() ) {
		int curr = q.front();
		q.pop();
		cout << curr << ' ';

		for(int neighbor : adj[curr]) {
			indegree[neighbor]--;
			if(indegree[neighbor] == 0) q.push(neighbor);
		}
	}
} 


void solve() {
	int n, m; cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<bool> vis(n, false);
	vector<int> topo;

	for(int i = 0 ; i < m ; ++i) {
		int a, b; cin >> a >> b;
		// --a, --b;
		adj[a].push_back(b);
	}
	
	// for(int i = 0 ; i < n ; ++i) {
	// 	if( !vis[i] ) dfs(i, adj, vis, topo);
	// }

	kahn_algo(adj);

	// reverse(topo.begin(), topo.end());
	// for(auto val : topo) cout << val << ' ';
	cout << endl;
}


int main() {
	solve();

	

}


