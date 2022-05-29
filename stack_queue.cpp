
// Implementing stack using two queues

#include <bits/stdc++.h>

using namespace std;

// stack using two queues
class Stack{
public:
	queue<int> q1, q2;

	void push(int data) {
		while( !q1.empty() ) {
			q2.push(q1.front());
			q1.pop();
		}

		q1.push(data);

		while( !q2.empty() ) {
			q1.push(q2.front());
			q2.pop();
		}
	}

	int pop() {
		if( q1.empty() ) {
			cout << "Stack empty" << endl;
			return -1;
		}

		int data = q1.front();
		q1.pop();
		return data;
	}
};


// Queue using two stacks
class Queue{
public:
	stack<int> s1, s2;

	void enqueue(int data) {
		while( !s1.empty() ) {
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(data);
	
		while( !s2.empty() ) {
			s1.push(s2.top());
			s2.pop();
		}
	}

	int dequeue() {
		if(s1.empty()) {
			cout << "Underflow\n";
			return -1;
		}

		int elem = s1.top();
		s1.pop();
		return elem;
	}
};


int main() {
	vector<int> keys = {1, 2, 3, 4, 5};
	Queue s;
	for(int key : keys) {
		s.enqueue(key);
	}

	for(int i = 0 ; i < keys.size() ; ++i) {
		cout << s.dequeue() << '\n';
	}

}
