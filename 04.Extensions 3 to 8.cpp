
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

int main()
{
	clsDblLinkedList <int> MyDblLinkedList;

	MyDblLinkedList.InsertAtBeginning(5);
	MyDblLinkedList.InsertAtBeginning(4);
	MyDblLinkedList.InsertAtBeginning(3);
	MyDblLinkedList.InsertAtBeginning(2);
	MyDblLinkedList.InsertAtBeginning(1);

	cout << "\nLinked List Content : \n";
	MyDblLinkedList.PrintList();
	cout << "\n";

	MyDblLinkedList.InsertAfter(1, 500);

	cout << "\nLinked List Content After Insert: \n";
	MyDblLinkedList.PrintList();

	/*MyDblLinkedList.Reverse();

	cout << "\nLinked List Content After Reverse : \n";
	MyDblLinkedList.PrintList();*/

    //MyDblLinkedList.UpdateItem(2, 500);
 
   //cout << "\nLinked List Content After Updating Item : \n";
   //	MyDblLinkedList.PrintList();
	//cout << "\nItem (2) Value is : " << MyDblLinkedList.GetItem(2);

	/*clsDblLinkedList <int>::Node* N1;

	N1 = MyDblLinkedList.GetNode(4);

	if (N1 != NULL)
		cout << "\n\nNode Value is : " << N1->Value << endl;
	else
		cout << "\n\nNode Not Found!\n";*/

	system("pause>0");
	return 0;

}
