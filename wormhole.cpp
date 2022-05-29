
/**
 * There is one spaceship. X and Y co-ordinate of the source of spaceship 
 * and destination spaceship is given. There is N number of wormholes; 
 * each wormhole has 5 values. First 2 values are starting co-ordinate 
 * of the wormhole and after that value no. 3 and 4 represent 
 * ending co-ordinate of the wormhole and last 5th value is represents 
 * a cost to pass through this wormhole. Now, these warmholes are 
 * bi-directional. Now the to go from (x1,y1) to (x2,y2) 
 * is abs(x1-x2)+abs(y1-y2). The main problem here is to find the 
 * minimum distance to reach spaceship from source to destination 
 * co-ordinate using any number of warm-hole. It is ok if you won't 
 * uses any warmhole.
**/


/**
	
**/

#include<bits/stdc++.h>
using namespace std;


class point {
public:
	int x,y;
};

class hole{
public:
	int x1,y1,x2,y2,cost;
};

vector<bool> visited;
int ans = 100000, n;

int calculate(point src, point dest) {
	return abs(src.x - dest.x) + abs(src.y - dest.y);
}

void f(point src, point dest, hole* a, int cost) {

	ans = min(ans, cost + calculate(src, dest));
	for(int i = 0 ; i < n ; ++i) {
		if ( !visited[i] ) {
			visited[i] = true;

			point temp1, temp2;int val;
			temp1.x = a[i].x1;
			temp1.y = a[i].y1;

			temp2.x = a[i].x2;
			temp2.y = a[i].y2;

			val = calculate(src, temp1);
			f(temp2, dest, a, cost + val + a[i].cost);

			val = calculate(src, temp2);
			f(temp1, dest, a, cost + val + a[i].cost);

			visited[i] = false;
		}
	}
}


int main() {
	int t; cin >> t;
	while(t--) {
		point src, dest;
		cin >> src.x >> src.y;
		cin >> dest.x >> dest.y;

		cin >> n;

		hole a[n];

		for(int i = 0 ; i < n ; ++i) {
			cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].cost;
		}

		visited.resize(n, false);

		f(src, dest, a, 0);
		cout << ans << endl;
	}
}


