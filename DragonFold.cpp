// DragonFold.cpp

#include <iostream>
#include "Node.cpp"
using namespace std;

void printNumber(int &count, bool data);

int main()
{
	//Variables
	bool assign = 0;								//Number inserted into list
	bool listEnd = 0;								//Flag for ending each scan through the list
	int lineCount = 0;								//Used for line breaks
	Node<bool>* head = new Node<bool>(1, NULL);		//Front of list
	Node<bool>* cursor;								//Used to splice in numbers


	cout << head->data << endl << endl;
	for (int x = 0; x < 8; x++)
	{
		head = new Node<bool>(1, head); //Attaches a 1 to the front of the list
		cursor = head;					//Starts the cursor at the front
		printNumber(lineCount, cursor->data);
		while (listEnd == 0)
		{
			cursor = cursor->NextNode();										//Cursor moves one position over
			printNumber(lineCount, cursor->data);
			cursor->InsertAfter(new Node<bool>(assign, cursor->NextNode()));	//Places a node w/ data value equal to "assign" after the current node
			cursor = cursor->NextNode();										//Moves cursor onto new node
			printNumber(lineCount, cursor->data);
			assign = !assign;
			if (cursor->NextNode() == NULL)
			{
				listEnd = 1;
				assign = 0;
			}
		}
		listEnd = 0;
		lineCount = 0;
		cout << endl << "Loop #" << x+1 << endl << endl;
	}
	system("pause");
	return 0;
}

void printNumber(int &count, bool data)
{
	count++;
	cout << data;
	if (count == 78)
	{
		cout << endl;
		count = 0;
	}
}