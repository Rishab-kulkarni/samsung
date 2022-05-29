
// complete binary tree -> A binary tree in which all the levels are completely filled except possibly the lowest one, which is filled from left. 
// max heap -> complete binary tree in which root is always maximum 
// heap representation done in array, if root is at index i, then left child is at index = 2*i + 1, right child is at index = 2*i + 2. 
// if given child index => i, then parent index `ceil(i/2) - 1`.
// If height of tree is h  => then max nodes  at height h = 2^h.
// Max nodes in the entire tree ==> 2^(h + 1) - 1.
// So in the array implementation of heap ==> max size of array should be = 2^(h + 1) - 1.
// If heap array size Range of leaves --> [floor(n / 2), n - 1] and internal nodes [0, floor(n/2) - 1]. 

/*
 Min heap complexity -> 
 Insert (element ) = O(logn)
 Search(element) = O(n)
 Find_min() = O(1)
 Delete_min() = O(logn)
*/


/* 
Time complexity to build a heap is O(n)
h = ceil(n / (2^h + 1))
h = 0 to logn

from h = 0 to logn sum(ceil(n / 2^h + 1))*h

n/2(2/4 + 3/8 + 4/16 + 5/32.....)  = n/2( <= 1) => n.

TC = O(n).
*/


// siftDown swaps a node that is too small with its largest child (thereby moving it down) until it is at least as large as both nodes below it.
// siftUp swaps a node that is too large with its parent (thereby moving it up) until it is no larger than the node above it. 


#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < n && a[left] > a[largest]) {
		largest = left;
	}

	if(right < n && a[right] > a[largest]) {
		largest = right;
	}

	if(largest != i) {
		swap(a[i], a[largest]);
		heapify(a, n, largest);
	}
}


void heapsort(vector<int> &a, int n) {

	// using shift down operation here for heapify.
	// i.e., At each iteration you shift an item down until it is in the correct location.


	// can also run the below for loop from 0 to n/2 - 1.
	// But in that case complexity of building a heap would be O(nlogn).

	
	for(int i = n/2 - 1 ; i >= 0 ; --i) {
		heapify(a, n, i);
	}

	for(int i = n - 1 ; i >= 0 ; --i) {
		swap(a[0], a[i]);
		heapify(a, i, 0);
	}
}


void solve() {
	int n; cin >> n; 
	vector<int> a(n);

	for(int i = 0 ; i < n ; ++i) cin >> a[i];

	heapsort(a, n);

	for(int i = 0 ; i < n ; ++i) cout << a[i] << ' ';
	cout << endl;

}

int main() {
	int t = 1;
	while(t--) solve();
}



