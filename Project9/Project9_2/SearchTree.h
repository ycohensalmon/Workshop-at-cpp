/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 2
The project adds numbers to a binary tree and also deletes and searches for books
*/
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	T successor(T val);                                             //search for successor
	void add(T value);                                              // add a value
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); } 	//delete duplicates values
	bool search(T value) { return search(Tree<T>::root, value); }   // search a value
	void remove(T val) { typename Tree<T>::Node* current = returnSearch(Tree<T>::root, val); remove(current); } //remove value from the binary tree
private:
	void remove(typename Tree<T>::Node*);
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);
	void deleteDuplicates(typename Tree<T>::Node* current);

	typename Tree<T>::Node* returnSearch(typename Tree<T>::Node*, T);
	typename Tree<T>::Node* findParent(typename Tree<T>::Node*, typename Tree<T>::Node*);
};

//----------------------------------------------------------
//  class SearchTree implementation
//----------------------------------------------------------

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)
		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->right, val);
	else
		if (!current->left)
		{
			current->left = new typename Tree<T>::Node(val);
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

//return a pointer to a node with the value we search for
template<class T>
typename Tree<T>::Node* SearchTree<T>::returnSearch(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return nullptr;
	//if the value in this node
	if (current->value == val)
		return current;
	//if the value bigger than the node value
	if (current->value < val)
		return returnSearch(current->right, val);
	//if the value is smaller or matches the node value
	else
		return returnSearch(current->left, val);
}

//find successor for the desired value
template <class T>
T SearchTree<T>::successor(T val)
{
	//a pointer to thnode with the original value
	typename Tree<T>::Node* current = returnSearch(Tree<T>::root, val);

	//if the node have right son, the seccessor have to be their
	if (current->right)
	{
		//return the minimum in the right side of the node with the original value
		current = current->right;
		while (current->left)
			current = current->left;

		return current->value;
	}

	//if the node have not right son we get the parent of the node
	typename Tree<T>::Node* p1 = findParent(current, Tree<T>::root);
	//while the node is the right son we are going up
	while (p1 && current == p1->right)
	{
		current = p1;
		p1 = findParent(current, Tree<T>::root);
	}
	if (!p1)
		throw "No successor";

	return p1->value;
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* current, typename Tree<T>::Node* parent)
{
	//if is empty tree
	if (!parent)
		return nullptr;
	//if the node is the root
	if (current == parent)
		return nullptr;
	//if we get the parent
	if (parent->left == current || parent->right == current)
		return parent;
	//if the poinetr parent is bigger than pointer current
	if (current->value <= parent->value)
		return findParent(current, parent->left);
	//if the pointer parent is smaller than pointer current
	if (current->value > parent->value)
		return findParent(current, parent->right);
}

template <typename T>
void SearchTree<T>::remove(typename Tree<T>::Node* current)
{
	//if the node have tow sons
	if (current && current->right && current->left)
	{
		T tmp = successor(current->value);
		remove(successor(current->value));
		current->value = tmp;
		return;
	}

	//pointer to the parent of the node to remove
	typename Tree<T>::Node* currentParent = findParent(current, Tree<T>::root);

	//if is leaf
	if (current && !current->right && !current->left)
	{
		//if the node is right son
		if (current == currentParent->right)
			currentParent->right = nullptr;
		//if the node is left son
		if (current == currentParent->left)
			currentParent->left = nullptr;

		current = nullptr;
	}

	//if the node have only right son
	if (current && current->right)
	{
		if (current == currentParent->right)
			currentParent->right = current->right;
		if (current == currentParent->left)
			currentParent->right = current->right;

		current = nullptr;
	}

	//if the node have only left son
	if (current && current->left)
	{
		if (current == currentParent->right)
			currentParent->right = current->left;
		if (current == currentParent->left)
			currentParent->left = current->left;

		current = nullptr;
	}
}

template<class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* current)
{
	//pointer to the other same value, he is should be in the left side of the current node
	typename Tree<T>::Node* toDelete = returnSearch(current->left, current->value);
	//while in the tree have more same value
	while (toDelete)
	{
		remove(toDelete);
		//pointer to the next same value in the left side
		toDelete = returnSearch(current->left, current->value);
	}
	//checking the right side for duplicates
	if (current->right)
		deleteDuplicates(current->right);
	//checking the left side for duplicates
	if (current->left)
		deleteDuplicates(current->left);
}