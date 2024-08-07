#include <bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node *left;
	Node *right;
	Node *nextRight;
	int h_dist;
	Node() {
		data = 0;
		left = nullptr;
		right = nullptr;
		nextRight = nullptr;
		h_dist = 0;
	}
	Node(int d) {
		data = d;
		left = nullptr;
		right = nullptr;
		nextRight = nullptr;
		h_dist = 0;
	}
};

void postorder(Node *R) {
	if (!R)
		return;
	postorder(R->left);
	postorder(R->right);
	cout << R->data << " ";
}
void preorder(Node *R) {
	if (!R)
		return;
	cout << R->data << " ";
	preorder(R->left);
	preorder(R->right);
}
int height_depth(Node *R) {
	if (!R)
		return 0;
	return ((max(height_depth(R->left), height_depth(R->right))) + 1);
}

void inorder(Node *R) {
	if (!R)
		return;
	inorder(R->left);
	cout << R->data << " ";
	inorder(R->right);
}

void makeR1(Node **R1) {
	(*R1) = new Node(1);
	(*R1)->left = new Node(2);
	(*R1)->right = new Node(3);
	(*R1)->left->left = new Node(4);
	(*R1)->left->right = new Node(5);
	(*R1)->right->left = new Node(6);
	(*R1)->right->right = new Node(7);
	return;
}
void makeBST(Node **R2) {
	(*R2) = new Node(40);
	(*R2)->left = new Node(20);
	(*R2)->right = new Node(60);
	(*R2)->left->left = new Node(10);
	(*R2)->left->right = new Node(30);
	(*R2)->right->left = new Node(50);
	(*R2)->right->right = new Node(70);
	return;
}
void makeR3(Node **R3) {
	(*R3) = new Node(20);
	(*R3)->left = new Node(10);
	(*R3)->right = new Node(30);
	(*R3)->left->left = new Node(5);
	(*R3)->left->left->left = new Node(2);
	(*R3)->left->left->left->right = new Node(3);
	(*R3)->right->left = new Node(15);
}
void makeR4(Node **R4) {
	(*R4) = new Node(1);
	(*R4)->left = new Node(2);
	(*R4)->right = new Node(3);
	(*R4)->left->right = new Node(5);
	(*R4)->right->left = new Node(6);
	(*R4)->right->right = new Node(7);
}

void makeR6(Node **R5) {
	(*R5) = new Node(1);
	(*R5)->left = new Node(2);
	(*R5)->right = new Node(3);
	(*R5)->left->left = new Node(4);
	(*R5)->left->right = new Node(5);
	(*R5)->right->left = new Node(6);
	(*R5)->right->right = new Node(7);
	(*R5)->left->left->left = new Node(8);
	(*R5)->left->left->right = new Node(9);
	(*R5)->left->right->left = new Node(10);
	(*R5)->left->right->right = new Node(11);
	(*R5)->right->left->left = new Node(12);
	(*R5)->right->left->right = new Node(13);
	(*R5)->right->right->left = new Node(14);
	(*R5)->right->right->right = new Node(15);

}
