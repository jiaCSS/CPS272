#pragma once
#include<iostream>
#include<cstring>
#include<string>
#include<sstream>



using namespace std;

struct Node {
	string data;
	Node* left;
	Node* right;
};


Node* getNewNode(string data) {

	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = newNode->right = NULL;

	return newNode;
}


Node* Insert(Node* root, string data) {

	if (root == NULL) {
		root = getNewNode(data);
	}
	else if (data <= root->data) {
		root->left = Insert(root->left, data);
	}
	else {
		root->right = Insert(root->right, data);
	}

	return root;
}


void preorder(Node* root, Node** destinaton) {
	if (root == NULL) return;

	cout << root->data << " ";
	if(destinaton != NULL) *destinaton = Insert(*destinaton, root->data);
	preorder(root->left, destinaton);
	preorder(root->right, destinaton);
}


void inorder(Node* root, Node** destinaton) {
	if (root == NULL) return;

	inorder(root->left, destinaton);
	cout << root->data << " ";
	if(destinaton != NULL) *destinaton = Insert(*destinaton, root->data);
	inorder(root->right, destinaton);
}


void postorder(Node* root, Node** destinaton) {

	if (root == NULL) return;

	postorder(root->left, destinaton);
	postorder(root->right, destinaton);
	cout << root->data << " ";
	if(destinaton != NULL) *destinaton = Insert(*destinaton, root->data);
}


int getLeafCount(Node* root) {
	if (root == NULL) return 0;
	if (root->left == NULL && root->right == NULL) return 1;
	else return getLeafCount(root->left) + getLeafCount(root->right);
}


int getMaxHeight(Node* root) {
	if (root == NULL) return -1;

	int leftHeight = getMaxHeight(root->left);
	int rightHeight = getMaxHeight(root->right);
	return max(leftHeight, rightHeight) + 1;
}








int main() {
	Node* t1 = NULL;
	Node* t2 = NULL;
	Node* t3 = NULL;

	string input;
	cout << "Enter a sentence: ";
	getline(cin, input);
	
	istringstream ss(input);
	string word;
	while (ss >> word) {
		cout << word << endl;
		t1 = Insert(t1, word);
	}
 
	cout << "\n\nPostorder: " << endl;;
	postorder(t1, &t2);
	cout << "\n\The height of tree is : "<< getMaxHeight(t1);
	cout << "\nThe leafs of tree is : " << getLeafCount(t1);

	cout << "\n\nPreorder: " << endl;;
	preorder(t2, &t3);

	cout << "\nThe height of tree is : " << getMaxHeight(t2);
	cout << "\nThe leafs of tree is : " << getLeafCount(t2);

	cout << "\n\nInorder: " << endl;
	inorder(t3, NULL);

	cout << "\nThe height of tree is : " << getMaxHeight(t3);
	cout << "\nThe leafs of tree is : " << getLeafCount(t3);





	return 0;
}