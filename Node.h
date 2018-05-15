//	Node.h
//	Author: Ali Selcuk AKYUZ (Copied/modified by Tony Delgado)
//	Mail: selcuk@retinarobotics.com || e174043@metu.edu.tr
//  Electrical and Electronics Engineering Department
//  Middle East Technical University - ANKARA
//	If any questions please send me an email
#pragma once  //Equivalent to using @ifndef <x>, #define <x>, etc
#include <iostream>

using namespace std;

template<class T>
class Node {
public:
	Node();														// Blank Constructor
	Node(const T& item, Node<T>* ptrnext = NULL);				// Constructor that sets data & next pointer
	T data;														// Should be 0, 1, or NULL
	Node<T>* NextNode();										// Access to the next node
																// List modification methods
	void InsertAfter(Node<T>* p);								// Add a node after the called one			
	Node<T>* DeleteAfter();										// Delete the node following the called one and returns it
	Node<T>* GetNode(const T& item, Node<T>* nextptr = NULL);	// Creates a new node & returns it as an object
																// Can be chained to create a list, such as:
																// Node<char> *head;
																// head = GetNode('A', GetNode('B', GetNode('C')));


private:
	Node<T> * next;												// Pointer to next node in list
};
