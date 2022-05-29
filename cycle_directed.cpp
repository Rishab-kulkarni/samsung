
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1000;
vector<int> parent(N, -1);
int cycle_start = -1, cycle_end = -1;

bool is_cyclic_dfs(int curr, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &dfsvis, int par) {
	vis[curr] = true;
	dfsvis[curr] = true;

	for(int neighbor : adj[curr]) {
		if ( !vis[neighbor] ) {
			parent[neighbor] = curr;
			if(is_cyclic_dfs(neighbor, adj, vis, dfsvis, curr)) return true;
		}

		else {
			if(dfsvis[neighbor]) {
				cycle_start = neighbor;
				cycle_end = curr;
				return true;
			}
		}
	}
	dfsvis[curr] = false;
	return false;

}


void solve() {
	int n,m; cin >> n >> m;
	
	vector<vector<int>> adj(n);
	vector<bool> vis(n, false), dfsvis(n, false);
	for(int i = 0 ; i < m ; ++i) {
		int a, b; cin >> a >> b;
		--a, --b;
		adj[a].push_back(b);
		// adj[b].push_back(a);
	}

	for(int i = 0 ; i < n ; ++i) {
		if( !vis[i] ) {
			if(is_cyclic_dfs(i, adj, vis, dfsvis, -1)) {
				break;
			}
		}
	}

	if(cycle_start == -1) cout << "No cycle\n";

	else {
		vector<int> cycle;
		cycle.push_back(cycle_start);
		for(int v = cycle_end ; v != cycle_start ; v = parent[v]) {
			cycle.push_back(v);
		}
		cycle.push_back(cycle_start);

		reverse(cycle.begin(), cycle.end());

		for(auto val : cycle) cout << val + 1<< ' ';
		cout << endl;

	}


	return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1; 
	// cin >> t;
	// cout << "t = " << t << endl;
	while(t--) solve();
}