
// if graph has odd length cycle -> then not bipartite.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
	int n,m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	
	for(int i = 0 ; i < m ; ++i) {
		int x, y; cin >> x >> y;
		--x, --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	vector<int> color(n, 0);
	vector<int> vis(n, false);

	int src = 0;
	bool is_bipartite = true;

	queue<int> q;
	q.push(src);
	vis[src] = true;
	color[src] = 1;
	while( !q.empty() ) {
		int curr = q.front();
		q.pop();

		for(int neighbor : adj[curr]) {
			if( !vis[neighbor] ) {
				vis[neighbor] = true;
				q.push(neighbor);
				color[neighbor] = color[curr] ^ 1;
			}

			else {
				is_bipartite &= (color[neighbor] != color[curr]);
			}
		}
	} 

	cout << (is_bipartite ? "YES" : "NO") << endl;
}
