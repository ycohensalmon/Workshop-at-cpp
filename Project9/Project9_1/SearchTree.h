/*
Yossef Cohen-Salmon T.Z. 317805588
Workshop in c ++
Exercise 9 Question 1
The project allows me to do actions on the binary tree like add limbs
or lower and measure the height of the tree etc.
*/
#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{
public:
	void add(T value);
	void remove(T value);
	bool  search(T value) { return search(Tree<T>::root, value); }
	T successor(T value) { return successor(Tree<T>::root, value); }
	void deleteDuplicates() { deleteDuplicates(Tree<T>::root); }
private:
	T successor(typename Tree<T>::Node* num, T value);
	void add(typename Tree<T>::Node* num, T value);
	bool search(typename Tree<T>::Node* num, T value);
	void  deleteDuplicates(typename Tree<T>::Node* num);
	void  deleteDuplicates(typename Tree<T>::Node* num, T value);

	typename Tree<T>::Node* find(typename Tree<T>::Node* num, T value);
	typename Tree<T>::Node* findParent(typename Tree<T>::Node* num, T value);
	typename Tree<T>::Node* findParent(T value) { return findParent(Tree<T>::root, value); }
};

template <class T>
void SearchTree<T>::add(T value)
{
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(value); 	// add value to binary search tree
		return;
	}
	add(Tree<T>::root, value);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* num, T value)
{
	if (num->value < value)

		if (!num->right)
		{
			num->right = new typename Tree<T>::Node(value);
			return;
		}
		else add(num->right, value);
	else

		if (!num->left)
		{
			num->left = new typename Tree<T>::Node(value);
			return;
		}
		else add(num->left, value);
}

template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* num, T value)
{
	if (!num)
		return false;	// not found
	if (num->value == value)
		return true;
	if (num->value < value) // If it is less than the value
		return search(num->right, value); 
	else
		return search(num->left, value);
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::find(typename Tree<T>::Node* num, T value)
{
	if (num->value == value) // return the num
		return num;
	if (num->value < value)             // If it is less than the value
		return find(num->right, value); // enter to the rigth child
	else
		return find(num->left, value);  // enter to the left child
}

template <class T>
T SearchTree<T>::successor(typename Tree<T>::Node* num, T value)
{//A method that looks for the successor of the value
	if (!search(Tree<T>::root, value))
		throw "no successor";
	//Find where the value is
	typename Tree<T>::Node* check = find(Tree<T>::root, value);
	//If it has a right son, we will go to right then we will go left to the endand find the successor
	if (check->right)
	{
		check = check->right;
		while (check->left)
			check = check->left;
		return check->value;
	}
	check = findParent(value);
	while (check->value < value)
		check = findParent(check->value);
	return check->value;
}

template <class T>
void SearchTree<T>::remove(T value)
{
	typename Tree<T>::Node* nodeToDelete = find(Tree<T>::root, value);
	if (!nodeToDelete->left && !nodeToDelete->right)
	{
		typename Tree<T>::Node* parent = findParent(value);
		if (parent->left && parent->left->value == value)
			parent->left = NULL;
		else
			parent->right = NULL;
		delete nodeToDelete;
		return;
	}
	if (!nodeToDelete->left)
	{
		typename Tree<T>::Node* parent = findParent(value);
		if (parent->left && parent->left->value == value)
			parent->left = nodeToDelete->right;
		else
			parent->right = nodeToDelete->right;
		delete nodeToDelete;
		return;
	}
	if (!nodeToDelete->right)
	{
		typename Tree<T>::Node* parent = findParent(value);
		if (parent->left && parent->left->value == value)
			parent->left = nodeToDelete->left;
		else
			parent->right = nodeToDelete->left;
		delete nodeToDelete;
		return;
	}

	T succes = successor(value);
	typename Tree<T>::Node* nodeOfSucces = find(Tree<T>::root, succes);
	if (!nodeOfSucces->left && !nodeOfSucces->right)
	{
		typename Tree<T>::Node* parent = findParent(nodeOfSucces->value);
		nodeToDelete->value = nodeOfSucces->value;
		if (parent->left && parent->left->value == nodeOfSucces->value)
			parent->left = NULL;
		if (parent->right && parent->right->value == nodeOfSucces->value)
			parent->right = NULL;
		delete nodeOfSucces;
		return;
	}
	if (!nodeOfSucces->left)
	{
		typename Tree<T>::Node* parent = findParent(nodeOfSucces->value);
		if (parent->left->value == nodeOfSucces->value)
		{
			nodeToDelete->value = nodeOfSucces->value;
			parent->left = nodeOfSucces->right;
		}
		else
		{
			nodeToDelete->value = nodeOfSucces->value;
			parent->right = nodeOfSucces->right;
		}
		delete nodeOfSucces;
		return;
	}
	if (!nodeOfSucces->right)
	{
		typename Tree<T>::Node* parent = findParent(nodeOfSucces->value);
		if (parent->left->value == nodeOfSucces->value)
			parent->left = nodeOfSucces->left;
		else
			parent->right = nodeOfSucces->left;
		delete nodeOfSucces;
		return;
	}
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::findParent(typename Tree<T>::Node* num, T value)
{//Auxiliary method for finding the parent
	if (!num)
		throw "no successor";
	if (num->left && num->left->value == value || num->right && num->right->value == value)
		return num;
	if (num->value < value)
		return findParent(num->right, value);
	else
		return findParent(num->left, value);
}

template <class T>
void SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* num)
{
	if (num)
	{
		deleteDuplicates(num->left);
		deleteDuplicates(num->right);
		if (num->left)
			deleteDuplicates(num->left, num->value);
	}
}

template <class T>
void  SearchTree<T>::deleteDuplicates(typename Tree<T>::Node* num, T value)
{
	if (num)
	{
		deleteDuplicates(num->left, value);
		deleteDuplicates(num->right, value);
		if (num->value == value)
			remove(num->value);
	}
}
