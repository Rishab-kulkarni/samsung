
#include <bits/stdc++.h>

using namespace std;

class Node {
public:
	int data;
	Node *next;
};

void middle(Node* head) {
	Node *fast, *slow;
	fast = slow = head;

	while(fast != nullptr and fast->next != nullptr) {
		fast = fast->next->next;
		slow = slow->next;
	}
	cout << "Middle of linked list = " << slow->data << endl;
}

Node* delete_mid(Node *head) {
	Node *prev, *fast, *slow;
	prev = fast = slow = head;

	while(fast != nullptr and fast->next != nullptr) {
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}

	prev->next = slow->next;
	delete slow;
	return head;
}

void reverse_rec(Node *head) {
	if(head == nullptr) return;
	reverse_rec(head->next);
	cout << head->data << ' ';
}

void reverse_itr(Node *head) {
	Node *prev, *curr, *next;

	prev = nullptr;
	curr = next = head;

	while( curr != nullptr ) {
		next = curr->next;
		curr->next = prev;

		prev = curr;
		curr = next;
	}
	head = prev;
}

void detect_loop(Node* head) {
	Node *fast, *slow;
	fast = slow = head;

	while(fast and fast->next) {
		slow = slow->next;
		fast = fast->next->next;

		if(slow == fast) {
			cout << "Loop detected\n"; return;
		}
	}
}

void remove_loop(Node* head) {
	// fast and slow pointer pointing to same node if loop present.
	// now to remove loop, start slow pointer from head and
	// iterate it one by one and also iterate the fast pointer one by one.
	// iterate both fast and slow one by one till fast->next != slow->next.
	// now the minute they are equal do fast->next == nullptr --> This step removes the loop.

	Node *slow, *fast;
	slow = fast = head;

	while(fast and fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if(fast == slow) break;
	}

	if(fast == slow) {
		slow = head;
		while(slow->next != fast->next) {
			slow = slow->next;
			fast = fast->next;
		}

		fast->next = nullptr;
	}
}


void intersection(Node *head1, Node *head2) {
	// most obvious approach is hashing   map<Node*, int>   or set<Node*>
	// traverse the first linked list completely and store those values in a set.  set<Node*>
	// now traverse the second linked list completely and check    
	// if value already present then that point is intersection point of linked list.

	Node *curr1, *curr2;
	curr1 = head1;
	curr2 = head2;

	while(curr1 != curr2) {
		if(curr1 == nullptr) curr1 = head2;
		else curr1 = curr1->next;

		if(curr2 == nullptr) curr2 = head1;
		else curr2 = curr2->next;
	}

	if( curr1 != nullptr ) cout <<  curr1->data << ' ';
}

void nthNodeFromEnd(Node* head, int n) {
	int len = 0;
	Node *temp;
	temp = head;

	while(temp) {
		temp = temp->next;
		len++;
	}

	Node *temp2;
	for(int i = 1 ; i < len - n + 1 ; ++i) {
		temp2 = temp2->next;
	}
	cout << "Nth Node from end = " << temp2->data << endl;


	temp = head;				// reference pointer to n nodes from beginning.
	int cnt = 0;
	while(temp && cnt != n) {
		temp = temp->next;
		cnt++;
	}

	temp2 = head;			// 
	while(temp && temp->next) {
		temp = temp->next;
		temp2 = temp2->next;
	}
	cout << "Nth node from end = " << temp2->data << endl; 	

}


int main() {

}


