

#include <bits/stdc++.h>

using namespace std;

const int N = 1000;
vector<vector<int>> adj(N);
vector<bool> visited(N, false);
vector<int> parent(N, -1);

int cycle_start = -1, cycle_end = -1;

bool dfs(int v, int par) {
	visited[v] = true;
	for(int u : adj[v]) {
		if(u == par) continue;

		if( !visited[u] ) {
			parent[u] = v;
			if(dfs(u, parent[u])) return true;
		} 
		else {		
			cycle_start = u;
			cycle_end = v;
			return true;
		}
		
 	}
 	return false;
}


int main() {
	int n,m;
	cin >> n >> m;
	

	for(int i = 0 ; i < m ; ++i) {
		int x, y; cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for(int i = 0 ; i < n ; ++i) {
		if( !visited[i]  && dfs(i, parent[i])) break;
	}

	if(cycle_start == -1) cout << "No cycle" << endl;
	else {
		vector<int> cycle;
		cycle.push_back(cycle_start);

		for(int v = cycle_end ; v != cycle_start ; v = parent[v]) {
			cycle.push_back(v);
		}
		cycle.push_back(cycle_start);
		reverse(cycle.begin(), cycle.end());

		for(auto node : cycle) cout << node + 1 << ' ';
		cout << endl;
	}
}


