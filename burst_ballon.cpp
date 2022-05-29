
#include <bits/stdc++.h>

using namespace std;


int n, cnt = 0;
vector<vector<int>> dp;

int f(int i, int j, vector<int> &a) {
	cnt++;
	if(i > j) return 0;

	if(dp[i][j] != -1) return dp[i][j];

	int mx = 0;
	for(int idx = i ; idx <= j ; ++idx) {
		int left = (i == 0 ? 1 : a[i - 1]);
		int right = (j == n - 1 ? 1 : a[j + 1]);

		int ans = f(i, idx - 1, a) + f(idx + 1, j, a);  
		if(left == 1 && right == 1) ans += a[idx];
		else ans += left*right;

		mx = max(mx, ans);

	}
	dp[i][j] = mx;
	return mx;
}

int main() {
	cin >> n;
	vector<int> a(n);

	dp.resize(n, vector<int>(n,-1));


	for(int i = 0 ; i < n ; ++i) cin >> a[i];

	cout << f(0, n - 1, a) << endl;	
	cerr << "cnt = " << cnt << endl;


}