
#include <iostream>
#include "clsDynamicArray.h"

using namespace std;

int main()
{
	clsDynamicArray <int> MyDynamicArray(5);

	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(2, 30);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);

	cout << "\nIs Empty? " << MyDynamicArray.IsEmpty();
	cout << "\nArray Size : " << MyDynamicArray.Size();

	cout << "\n\nArray Items : \n";
	MyDynamicArray.PrintList();

	MyDynamicArray.InsertAtBeginning(400);
	cout << "\n\nArray After Insert 400 At Beginning : ";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.InsertBefore(2, 500);
	cout << "\n\nArray After Insert 500 Before Index 2 : ";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.InsertAfter(10, 600);
	cout << "\n\nArray After Insert 600 After Index 2 : ";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.InsertAtEnd(800);
	cout << "\n\nArray After Insert 800 At End : ";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	system("pause>0");
	return 0;

	/*MyDynamicArray.InsertAt(2, 500);
	cout << "\n\nArray After Insert 500 After 2 : ";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();*/

	/*int Index = MyDynamicArray.Find(30);

	if (Index == -1)
		cout << "\n\nItem was not found :-(\n";
	else
		cout << "\n\n30 was found at index : " << Index << "\n";

	MyDynamicArray.DeleteItem(30);
	cout << "\n\nArray Items After Deleting 30 :";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";

	MyDynamicArray.PrintList();*/

	/*MyDynamicArray.DeleteFirstItem();
	cout << "\n\nArray Items After Deleting First Item : \n";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();

	MyDynamicArray.DeleteLastItem();
	cout << "\n\nArray Items After Deleting Last Item : \n";
	cout << "\nArray Size : " << MyDynamicArray.Size() << "\n";
	MyDynamicArray.PrintList();*/

	/* MyDynamicArray.DeleteItemAt(2);

	cout << "\n\nArray Items After Deleting Item(2) : \n";
	MyDynamicArray.PrintList();

	cout << "\n\nArray Size : " << MyDynamicArray.Size() << "\n"; */

	/*cout << "\n\nItem (2) : " << MyDynamicArray.GetItem(2) << "\n";

	MyDynamicArray.Reverse();

	cout << "\nArray Items After Reverse : \n";
	MyDynamicArray.PrintList();

	MyDynamicArray.Clear();

	cout << "\n\nArray Items After Clear : \n";
	MyDynamicArray.PrintList();*/

	/*MyDynamicArray.Resize(2);
	cout << "\n\nArray Size : " << MyDynamicArray.Size();
	cout << "\n\nArray Items After Resize To 2 : \n";
	MyDynamicArray.PrintList();

	MyDynamicArray.Resize(10);
	cout << "\n\nArray Size : " << MyDynamicArray.Size();
	cout << "\n\nArray Items After Resize To 10 : \n";
	MyDynamicArray.PrintList();*/

	

}
