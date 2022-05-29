

// Hamiltonian cycle - A path that each node exactly once.
// tsp problem -> min cost hamiltonian cycle

// brute force way is to generate all n! permutations of the given hamiltonian cycle.

// other approach is to use dynamic programming -> top down dp -> recursion + memoization


#include <bits/stdc++.h>

using namespace std;

int n, VISITED_ALL;

// int a[10][10] = {
// 	{0,20,42,25},
//     {20,0,30,34},
//     {42,30,0,10},
//     {25,34,10,0}
// };

int a[10][10];

int f(int mask, int pos, vector<vector<int>> &dp) {
	if(mask == VISITED_ALL) {
		return a[pos][0];
	}


	if(dp[mask][pos] != -1) 
		return dp[mask][pos];


	int ans = INT_MAX;
	for(int city = 0 ; city < n ; ++city) {
		if((mask & ( 1 << city)) == 0) {
			int newAns = a[pos][city] + f(mask | ( 1 << city), city, dp);
			ans = min(ans, newAns);
		}
	}
	dp[mask][pos] = ans;
	return dp[mask][pos];
}


int main() {
	n = 5;
	VISITED_ALL = ( 1 << n ) - 1;

	for(int i = 0 ; i < n ; ++i) {
		for(int j = 0 ; j < n ; ++j) cin >> a[i][j];
	}

	vector<vector<int>> dp(VISITED_ALL, vector<int>(n, -1));
	cout << f(1, 0, dp) << endl;
}






/*
algorithm				 dependent variable   		independent variable 			purpose
--------------------------------------------------------------------------------------------------------------
linear regression			continous						 continous				used to find causal relationships 
																						b/w independent and dependent
---------------------------------------------------------------------------------------------------------------------------

logistic regression			binary categorical				categorical / continous		used to find causal effect relationship
																						b/w independent and dependent 
----------------------------------------------------------------------------------------------------------------------------
discriminant analysis        categorical					continous					to find most discriminant independent
																						variable
-----------------------------------------------------------------------------------------------------------------------------

decision tree				categorical						categorical and continous    used to classify the records in 
																					      pictorial format
-----------------------------------------------------------------------------------------------------------------------------

naive bayes					categorical categorical			categorical					  classification technique used to classify
																						  records using posterior probability. 

---------------------------------------------------------------------------------------------------------------------------------

kNN																						 used to classify records with help of 
																						  euclidean distance
---------------------------------------------------------------------------------------------------------------------------------

svm																						classification technique used to classify
																						records with hyperplane. 																					  

*/