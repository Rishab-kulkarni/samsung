
#include <bits/stdc++.h>

using namespace std;

int main() {
	int arr[2][100] = {0};
	int size = 0, x;
	string s;

	cin >> x >> s;

	int temp = 0, commit = 0, neg = 0, level = 0;
	for(int i = 0 ; i < int(s.size()) ; ++i) {
		if(s[i] == '(' || s[i] == ')' ) {
			if(commit == 1) {
				if(neg == 1) {
					temp = temp*-1;
					neg = 0;
				}

				arr[0][size] = level;
				arr[1][size] = temp;
				size++;
				temp = 0;
			}

			if(s[i] == '(') level++;
			if(s[i] == ')') level--;

			commit = 0;
		}

		else if(s[i] == '-') {
			neg = 1;
			commit = 1;
		}

		else {
			temp = temp*10 + (s[i] - '0');
			commit = 1;
		}
	}

	int temp0, temp1;

	// for(int i = 0 ; i < size - 1 ; ++i) {
	// 	for(int j = i + 1 ; j < size ; ++j) {
	// 		swap(arr[0][j], arr[0][i]);
	// 		swap(arr[1][j], arr[1][i]);
	// 	}
	// }

	int sum = 0;
	for(int i = 0 ; i < size ; ++i) {
		if(arr[0][i] == x + 1) sum += arr[1][i];
	}
	cout << sum << endl;
}