// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};

BstNode* GetNewNode(int data)
{
	BstNode* newNode = new BstNode();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* Insert(BstNode* root, int data)
{
	if (root == NULL)
	{
		root = GetNewNode(data);
	}
	else if (data <= root->data)
	{
		root->left = Insert(root->left, data);
	}
	else
	{
		root->right = Insert(root->right, data);
	}
	return root;
}

bool Search(BstNode* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	else if (root->data == data)
	{
		return true;
	}
	else if (data <= root->data)
	{
		return Search(root->left, data);
	}
	else
	{
		return Search(root->right, data);
	}


}


int FindMin(BstNode* root)
{
	if (root == NULL) {
		cout << "Error : Tree is empty\n";
		return -1;
	}
	BstNode* current = root;
	while (current->left != NULL) {
		current = current->left;
	}
	cout << "Min Number is: " << current->data << endl;

	BstNode* currentRight = root;
	while (currentRight->right != NULL) {
		currentRight = currentRight->right;
	}
	cout << "Max Number is: " << currentRight->data << endl;

	return current->data;
}


int main()
{
	BstNode* root = NULL;

	root = Insert(root, 15);
	root = Insert(root, 10);
	root = Insert(root, 12);
	root = Insert(root, 20);
	root = Insert(root, 25);
	root = Insert(root, 8);
	root = Insert(root, 12);
	FindMin(root);
	int number;

	cout << "Enter number be searched\n";
	cin >> number;
	if (Search(root, number) == true) cout << "Found\n";
	else cout << "Not found\n";

	return 0;
}

