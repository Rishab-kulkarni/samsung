
#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

const int N = 100;
int a[N][N], n, VISITED_ALL;



int f(int mask, int pos) {
	if(mask == VISITED_ALL) {
		return a[pos][0];
	}

	int ans = INT_MAX;
	for(int i = 0 ; i < n ; ++i) {
		if((mask & ( 1 << i)) == 0) {
			int temp = a[pos][i] + f((mask | ( 1 << i)), i);
			ans = min(ans, temp);
		}
	}
	return ans;
}



int main() {
	int t; cin >> t;
	while( t-- ) {
		memset(a, 0, sizeof(a));
		cin >> n;
		VISITED_ALL = (1 << n) - 1;

		int dp[VISITED_ALL][n];

		for(int i = 0 ; i < n ; ++i) {
			for(int j = 0 ; j < n ; ++j) cin >> a[i][j];
		}

		cout << f(1, 0) << endl;
	}
}