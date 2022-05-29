 
// the main idea in endoscopy is to do a breadth first search traversal
// implement your own queue
// take care of directions left, right, up and down.
// every time you push a cell into the queue decrease the length of the endoscope.

#include<iostream>
using namespace std;

int n,m, front, back;
int a[1000][1000];
bool visited[1000][1000];

class node{
public:
	int x,y,l;
};

node q[1000000];

void init() {
	front = 0;
	back = 0;
}

void push(node curr) {
	q[back++] = curr;
}

node pop() {
	return q[front++];
}

bool empty() {
	return (front == back);
}


bool is_valid(int x, int y) {
	return (x >= 0 && x < n && y >= 0 && y < m);
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


int f(int e_x, int e_y, int e_l) {
	int ans = 0;

	push({e_x, e_y, e_l});
	visited[e_x][e_y] = true;
	while( !empty() ) {
		node curr = pop();
		int x = curr.x, y = curr.y, l = curr.l;
		
		if(l == 0) continue;
		ans++;
		// left = x, y -> x, y-1 
		if(is_valid(x, y - 1) && left(x, y) && right(x, y - 1) && !visited[x][y - 1]) {
			push({x, y - 1, l - 1});
			visited[x][y - 1] = true;
		}

		// right x,y -> x,y+1
		if(is_valid(x, y + 1) && right(x, y) && left(x, y + 1) && !visited[x][y + 1]) {
			push({x, y + 1, l - 1});
			visited[x][y + 1] = true;
		}

		// up x,y -> x-1,y
		if(is_valid(x - 1, y) && up(x, y) && down(x - 1, y) && !visited[x - 1][y]) {
			push({x -1, y, l - 1});
			visited[x - 1][y] = true;
		}

		// down x, y -> x + 1,y
		if(is_valid(x + 1, y) && down(x, y) && up(x + 1, y) && !visited[x + 1][y]) {
			push({x + 1, y, l - 1});
			visited[x + 1][y] = true;
		}
	}
	return ans;
}

int main() {
	int t; cin >> t;
	while(t--) {
		int x, y, l;
		cin >> n >> m >> x >> y >> l;

		init();
		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < m ; ++j) {
				cin >> a[i][j];
				visited[i][j] = false;
			}
		}

		if(a[x][y] == 0) cout << a[x][y] << endl;
		else cout << f(x, y, l) << endl;
	}
}