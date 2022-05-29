
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> a(n);

	for(int i = 0 ; i < n ; ++i) cin >> a[i];

	// dp[i] --> Length of lis ending at i.
	vector<int> dp(n, 0); 
	
	for(int i = 0 ; i < n ; ++i) {
		dp[i] = 1;
		for(int k = 0 ; k < i ; ++k) {
			if(a[k] < a[i])
			dp[i] = max(dp[i], dp[k] + 1);
		}
	}


}