#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
using namespace std;


template <class T>

class BinaryTree
{
private:
	struct TreeNode {
		T value; //value in node
		TreeNode* left; //pointer to left child
		TreeNode* right; //pointer to right child
	};
	TreeNode* root; //pointer to root


	//private mem fucntions
	void insert(TreeNode*&, TreeNode*&);
	void destroySubTree(TreeNode*);
	void deleteNode(T, TreeNode*&);
	void makeDeletion(TreeNode*&);
	void displayInOrder(TreeNode*) const;
	void displayPreOrder(TreeNode*) const;
	void displayPostOrder(TreeNode*) const;

public:
	//constructor
	BinaryTree() { root = nullptr; }

	//destructor
	~BinaryTree() { destroySubTree(root); }

	//operations
	bool searchNode(T);
	void insertNode(T);

	

	void remove(T);

	void displayInOrder() const {
		displayInOrder(root);
	}
	void displayPreOrder() const {
		displayPreOrder(root);
	}
	void displayPostOrder() const {
		displayPostOrder(root);
	}
};


template <class T>
void BinaryTree<T>::insert(TreeNode*& nodePtr, TreeNode*& newNode) {
	if (nodePtr == nullptr)
		nodePtr = newNode; //insert node
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode) ; //search left branch
	else
			insert(nodePtr->right, newNode); //search right branch
}



template <class T> 
void BinaryTree<T>::insertNode(T item) {
	TreeNode* newNode = nullptr;

	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;

	insert(root, newNode);
}


template <class T>
void BinaryTree<T>::destroySubTree(TreeNode* nodePtr) {
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}


 template <class T>
 bool BinaryTree<T>::searchNode(T item) {
	TreeNode* nodePtr = root;
	while (nodePtr)
	{
		if (nodePtr->value == item)
			return true;
		else if (item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

 

 template <class T>
 void BinaryTree<T>::deleteNode(T item, TreeNode*& nodePtr) {
	 if (item < nodePtr->value)
		 deleteNode(item, nodePtr->left);
	 else if (item > nodePtr->value)
		 deleteNode(item, nodePtr->right);
	 makeDeletion(nodePtr);
 }


 template <class T>
 void BinaryTree<T>::makeDeletion(TreeNode*& nodePtr) {
	 TreeNode* tempNodePtr = nullptr;

	 if (nodePtr == nullptr)
		 cout << "Cannot delete empty node. \n";
	 else if (nodePtr->right == nullptr)
	 {
		 tempNodePtr = nodePtr;
		 nodePtr = nodePtr->left;
		 delete tempNodePtr;
	 }
	 else if (nodePtr->left == nullptr)
	 {
		 tempNodePtr = nodePtr;
		 nodePtr = nodePtr->right;
		 delete tempNodePtr;
	 }
	 else
	 {
		 tempNodePtr = nodePtr->right;
		 while (tempNodePtr->left)
			 tempNodePtr = tempNodePtr->left;
		 tempNodePtr->left = nodePtr->left;
		 tempNodePtr = nodePtr;
		 nodePtr = nodePtr->right;
		 delete tempNodePtr;
	 }
 }

 

 template <class T>
 void BinaryTree<T>::displayInOrder(TreeNode* nodePtr) const {
	 if (nodePtr)
	 {
		 displayInOrder(nodePtr->left);
		 cout << nodePtr->value << endl;
		 displayInOrder(nodePtr->right);
	 }
 }



 template <class T>

 void BinaryTree<T>::displayPreOrder(TreeNode* nodePtr) const {

	 if (nodePtr) {
		 cout << nodePtr->value << endl;
		 displayPreOrder(nodePtr->left);
		 displayPreOrder(nodePtr->right);
	 }

 }



 template <class T>
 void BinaryTree<T>::displayPostOrder(TreeNode* nodePtr) const {

	 if (nodePtr) {
		 displayPostOrder(nodePtr->left);
		 displayPostOrder(nodePtr->right);
		 cout << nodePtr->value << endl;
	 }
 }

		 



#endif // !BINARYTREE_H