
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int n,m;
int a[N][N];
bool visited[N][N];


class node {
public:
	int x, y, l;
};

node q[100000];

int front, back;

void init() {
	front = back = 0;
}

void push(node temp) {
	q[back++] = temp;
} 

node pop() {
	return q[front++];
}

bool empty() {
	return (front == back);
}

bool is_valid(int x, int y) {
	return (x < n && x >= 0 && y < m && y >= 0);
}

bool left(int x, int y) {
	return (a[x][y] == 1 or a[x][y] == 3 or a[x][y] == 6 or a[x][y] == 7);
}

bool right(int x, int y) {
	return (a[x][y] == 1 or a[x][y] == 3 or a[x][y] == 4 or a[x][y] == 5);
}

bool up(int x, int y) {
	return (a[x][y] == 1 or a[x][y] == 2 or a[x][y] == 4 or a[x][y] == 7);
}

bool down(int x, int y) {
	return (a[x][y] == 1 or a[x][y] == 2 or a[x][y] == 5 or a[x][y] == 6);
}



int f(int r, int c, int l) {
	int ans = 0;

	push({r, c, l});
	visited[r][c] = true;

	while( !empty() ) {
		node curr = pop();
		int x = curr.x, y = curr.y, l = curr.l;

		if( l == 0 ) continue;
		ans++;

		// x,y
		// left --> x,y-1

		if(is_valid(x, y - 1) && !visited[x][y - 1] && left(x,y) && right(x, y - 1)) {
			push({x, y - 1, l - 1});
			visited[x][y - 1] = true;
		}

		// x,y
		// right --> x, y + 1
		if(is_valid(x, y + 1) && !visited[x][y + 1] && right(x, y) && left(x, y + 1)) {
			push({x, y + 1, l - 1});
			visited[x][y + 1] = true;
		}

		// x,y
		// up --> x-1, y
		if(is_valid(x - 1, y) && !visited[x - 1][y] && up(x, y) && down(x - 1, y)) {
			push({x - 1, y, l - 1});
			visited[x - 1][y] = true;
		}

		// x,y
		// down --> x + 1, y
		if(is_valid(x + 1, y) && !visited[x + 1][y] && down(x, y) && up(x + 1, y)) {
			push({x + 1, y, l - 1});
			visited[x + 1][y] = true;
		}
	}

	return ans;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int r,c,l;
		cin >> n >> m >> r >> c >> l;

		init();
		memset(a, 0, sizeof(a));
		memset(visited, false, sizeof(visited));
		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < m ; ++j) cin >> a[i][j];
		}

		if(a[r][c] == 0) {
			cout << 0 << '\n';
		}
		else cout << f(r, c, l) << '\n';
	}
}
