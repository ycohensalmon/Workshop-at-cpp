/*
itzchak walles 021996954
Workshop in C++
Exercise 9.2
library with binary search tree. adding a abook, removing a book, and print entire library(all the tree) in order.
*/


#pragma once

#include "QueueVector.h"
#include <cmath>
#include <iostream>
using namespace std;

//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T>
class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val) : value(val), left(NULL), right(NULL) {}
		Node(T val, Node* l, Node* r) : value(val), left(l), right(r) {}
	};		//end of Node class

	//data member of tree
	Node* root;

public:
	Tree() { root = NULL; }	 // initialize tree
	~Tree();

	bool isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

	int height() { return height(root); }//height of the tree
	void reflect() { reflect(root); }//reflect of the tree
	void breadthScan() { breadthScan(root); }//print out the tree to the breadth

private:
	//private function for not give acsses to user
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

	int  height(Node* current);
	void reflect(Node* current);
	void breadthScan(Node* current);
};




//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------

template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != NULL)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}

template <class T>
bool Tree<T>::isEmpty() const
{
	return  root == NULL;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(Node* current)
{    // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

//the height of the tree
template <typename T>
int Tree<T>::height(Node* current)
{
    //the tree is not exist
	if (!current)
		return -1;

    //return the heigher side
	if (height(current->right) + 1 >= height(current->left) + 1)
		return height(current->right) + 1;

	return height(current->left) + 1;
}


template <typename T>
void Tree<T>::reflect(Node* current)
{
    //the end of the tree
	if (!current)
		return;

    //temp for switch
	Node* tmp = current->right;
	//swith between right and left side
	current->right = current->left;
	current->left = tmp;

    //recursion to get all the nodes
	reflect(current->right);
	reflect(current->left);
}


template <typename T>
void Tree<T>::breadthScan(Node* current)
{
    //the tree is empty
	if (!current)
		return;

    //queue to insert the nodes by the breadth of the tree
	QueueVector<Node*> myTree(2 * pow(2, height()) - 1);

    //insert the root
	myTree.enqueue(current);

    //while the queue is not empty
	while (!myTree.isEmpty())
	{
	    //if the node in the front have left son
		if (myTree.front()->left)
			myTree.enqueue(myTree.front()->left);
		//if the node in the front have right son
		if (myTree.front()->right)
			myTree.enqueue(myTree.front()->right);
        
        //print out thre front of the queue
		cout << myTree.dequeue()->value << " ";
	}

	cout << endl;
}