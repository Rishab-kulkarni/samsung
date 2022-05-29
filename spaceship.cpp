
#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int a[N][N];


void upd(int row) {
	if(row < 0) return;

	int uplimit = max(0, row - 4);
	for(int i = row ; i >= uplimit ; --i) {
		for(int j = 0 ; j <= 4 ; ++j) {
			if(a[i][j] == 2) a[i][j] = 0;
		}
	}
}



int find_max(int row, int col, int bombs) {
	if(row < 0 || col < 0 || col >= 5) return 0;

	int answer = 0;
	if(row > 0 && a[row - 1][col] != 2) {
		answer = max(answer, a[row - 1][col] + find_max(row - 1, col, bombs));
	}

	if(col > 0 && row > 0 && a[row - 1][col - 1] != 2) {
		answer = max(answer, a[row - 1][col - 1] + find_max(row - 1, col - 1, bombs));
	}

	if(col < 4 && row > 0 && a[row - 1][col + 1] != 2) {
		answer = max(answer, a[row - 1][col + 1] + find_max(row - 1, col + 1, bombs));
	}


	if(answer == 0 && bombs > 0) {
		upd(row - 1);
		answer = find_max(row, col, bombs - 1);
	}
	return answer;
}


int main() {
	int t = 1; //cin >> t;
	while(t--) {
		int row; cin >> row;

		for(int i = 0 ; i < row ; ++i) {
			for(int j = 0 ; j < 5 ; ++j) cin >> a[i][j];
		}

		cout << find_max(row, 2, 1) << endl;
	}
}