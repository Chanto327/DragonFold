// Implementation of Node class
// Author: Ali Selcuk AKYUZ (Copied/modified by Tony Delgado)
// Mail: selcuk@retinarobotics.com || e174043@metu.edu.tr
// Electrical and Electronics Engineering Department
// Middle East Technical University - ANKARA 
// If any questions please send me an email

#include "Node.h"

template<class T>
Node<T>::Node()
{
	//Default constructor
	//Allows creation of object without initialization
}

template<class T>
Node<T>::Node(const T& item, Node<T>* ptrnext)
{
	this->data = item;		// a->b is equivalent to (*a).b
	this->next = ptrnext;
}

template<class T>
Node<T>* Node<T>::NextNode()
{
	return this->next;
}   //Retrieves the next node in the list

template<class T>
void Node<T>::InsertAfter(Node<T> *p)
{
	// Must link the new node to the rest of the list first to avoid losing it
	p->next = this->next;

	// Now link prior node to p
	this->next = p;
}

template<class T>
Node<T>* Node<T>::DeleteAfter()
{
	// Store next node in a temporary spot
	Node<T>* tempNode = next;
	// Check if there is a next node
	if (next != NULL)
		next = next->next;
	// To explain, a = b->c; 'a' is the "next" pointer of the current node.  b->c means the 'next' pointer of the current node's next node.
	//	|  a |	 /->|  b |	 /->|  c |
	//	|____|	/	|____|	/	|____|
	//	|next|-/	|next|-/	|next|
	// BECOMES
	//	|  a |	 /------------->|  c |
	//	|____|	/				|____|
	//	|next|-/				|next|

	return tempNode; //Returns NULL if no node was deleted
}

template<class T>
Node<T>* GetNode(const T& item, Node<T> nextptr = NULL)
{
	Node<T>* newnode; //Local pointer for new node
	newnode = new Node<T>(item, nextptr);
	if (newnode == NULL)
	{
		cerr << "Memory allocation failed." << endl;
		exit(1);
	}
	return newnode;
}	//At present (5/12/2018) I am uncertain of the purpose of this function