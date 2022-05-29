#include<bits/stdc++.h>
using namespace std;

 int f(int i, int j, vector<int> &nums, vector<vector<int>> &dp) {
        
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans = -1;
    for(int idx = i ; idx <= j ; ++idx) {
        int cost = nums[i - 1]*nums[idx]*nums[j + 1] + f(i, idx - 1, nums, dp) + f(idx + 1, j, nums, dp);
        ans = max(ans, cost);
    }
    dp[i][j] = ans;
    return dp[i][j];
}


int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

    // cout << f(1, n, nums, dp) << endl;
    return f(1, n, nums, dp);

}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i) cin >> a[i];
    
    cout << maxCoins(a) << endl;
}

