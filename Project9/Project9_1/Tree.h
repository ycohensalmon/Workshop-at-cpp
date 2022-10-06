/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 1
The project allows me to do actions on the binary tree like add limbs
or lower and measure the height of the tree etc.
*/
#pragma once
#include <iostream>
#include "QueueVector.h"
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
	int isEmpty() const;
	void clear() { clear(root); root = NULL; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int height() { return height(root); }
	void reflect() { reflact(root); }
	void breadthScan() { breadthScan(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

private:
	//private function for not give acsses to user
	void reflact(Node* num);
	int height(Node* num);
	void clear(Node* num);
	void preOrder(Node* num);
	void inOrder(Node* num);
	void postOrder(Node* num);
	void breadthScan(Node* num);
};


//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() { if (root != NULL)clear(root); }

template <class T>
int Tree<T>::isEmpty() const { return  root == NULL; }

template <class T>
void Tree<T>::clear(Node* num)
{
	if (num)
	{    // Release memory associated with children
		if (num->left)
			clear(num->left);
		if (num->right)
			clear(num->right);
		delete num;
	}
}

template <class T>
void Tree<T>::preOrder(Node* num)
{    // visit Node, left child, right child
	if (num)
	{   // process num Node
		process(num->value);
		preOrder(num->left);
		preOrder(num->right);
	}
}

template <class T>
void Tree<T>::inOrder(Node* num)
{    // visit left child, Node, right child
	if (num)
	{
		inOrder(num->left);
		process(num->value);
		inOrder(num->right);
	}
}

template <class T>
void Tree<T>::postOrder(Node* num)
{    // visit left child, right child, node
	if (num)
	{
		postOrder(num->left);
		postOrder(num->right);
		process(num->value);
	}
}

template <class T>
int Tree<T>::height(Node* num)
{	//Passes recursion on the tree from below.  Each time he will take the
	//largest between right and left and thus we will get the maximum height
	if (!num)
		return -1;
	return max(height(num->right), height(num->left)) + 1;
}

template <class T>
void Tree<T>::reflact(Node* num)
{   //Stop condition
	if (!num->left && !num->right)
		return;
	//if there are two child
	if (num->left != NULL && num->right != NULL)
	{
		reflact(num->left);
		reflact(num->right);
		Node* temp = num->left;
		num->left = num->right;
		num->right = temp;
	}
	//if there is one child (left)
	if (num->left != NULL && num->right == NULL)
	{
		reflact(num->left);
		num->right = num->left;
		num->left = NULL;
	}
	//if there is one child (right)
	if (num->left == NULL && num->right != NULL)
	{
		reflact(num->right);
		num->left = num->right;
		num->right = NULL;
	}
}

template <class T>
void Tree<T>::breadthScan(Node* num)
{
	QueueVector<Node*>* arr = new QueueVector<Node*>(100);
	arr->enqueue(num);
	Node* print;
	while (!arr->isEmpty())
	{
		print = arr->dequeue();
		cout << print->value << " ";
		if (print->left != NULL)
			arr->enqueue(print->left);
		if (print->right != NULL)
			arr->enqueue(print->right);
	}
}