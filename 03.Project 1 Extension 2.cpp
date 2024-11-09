
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
	clsDblLinkedList <int> MyDblLinkedList;

	if (MyDblLinkedList.IsEmpty())
		cout << "\n\nYes, Linked List is Empty\n";
	else
		cout << "\n\nNo, Linked List is not Empty\n";

	MyDblLinkedList.InsertAtBeginning(5);
	MyDblLinkedList.InsertAtBeginning(4);
	MyDblLinkedList.InsertAtBeginning(3);
	MyDblLinkedList.InsertAtBeginning(2);
	MyDblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Content : \n";
	MyDblLinkedList.PrintList();

	cout << "\n\nNumber of items in the linked list = " << MyDblLinkedList.Size();

	if (MyDblLinkedList.IsEmpty())
		cout << "\n\nYes, Linked List is Empty\n";
	else
		cout << "\n\nNo, Linked List is not Empty\n";

	system("pause>0");
	return 0;

}