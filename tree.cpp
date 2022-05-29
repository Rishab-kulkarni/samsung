
#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node *left, *right;
	Node() : data(0), left(nullptr), right(nullptr) { }
	Node(int data) : data(data), left(nullptr), right(nullptr) { }
};


Node* insert(Node* root, int data) {
	if(root == nullptr) {
		return new Node(data);
	}

	if(data < root->data) {
		root->left = insert(root->left, data);
	}

	else if(data > root->data) {
		root->right = insert(root->right, data);
	}
	return root;
}

void inorder(Node *root) {
	if(root == nullptr) return;

	inorder(root->left);
	cout << root->data << ' ';
	inorder(root->right);
}


pair<bool,Node*> search(Node *root, int data) {
	
	if(root == nullptr) return {false, nullptr};
	if(root->data == data) return {true, root};

	if(data < root->data) {
		return search(root->left, data);
	}
	else if(data > root->data) {
		return search(root->right, data);
	}
	return {false, nullptr};
}

int main() {
	int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }

    int val = 16;
    auto v = search(root, val).second;

    if(v != nullptr) {
    	cout << v->data << endl;
    }

    // cout << (search(root, val).second ? "YES" : "NO") << endl;
 
}