
#include<bits/stdc++.h>
using namespace std;

const int N = 100;
class A {
public:
	int x, y;
};

A a[N];
bool visited[N];

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int f(int n, int x, int y, int hx, int hy, int index, int cnt) {
	if(cnt == n) {
		return dist(x, y, hx, hy);
	}

	int ans = INT_MAX;
	for(int i = 0 ; i < n ; ++i) {
		if( !visited[i] ) {
			visited[i] = true;
			int val = dist(x, y, a[i].x, a[i].y) + f(n, a[i].x, a[i].y, hx, hy, i, cnt + 1);
			ans = min(ans, val);
			visited[i] = false;
		}
	}
	return ans;
}


int main() {
	int n; cin >> n;
	int ox, oy; cin >> ox >> oy;
	int hx, hy; cin >> hx >> hy;

	for(int i = 0 ; i < N ; ++i) a[i].x = a[i].y = 0, visited[i] = false;

	for(int i = 0 ; i < n ; ++i) {
		int x, y; cin >> x >> y;
		a[i].x = x;
		a[i].y = y;
	}

	int ans = f(n, ox, oy, hx, hy, 0, 0);
	cout << ans << endl;
}