
#include <iostream>
#include "clsMyQueue.h"
using namespace std;

int main()
{
	clsMyQueue <int> MyQueue;

	MyQueue.push(10);
	MyQueue.push(20);
	MyQueue.push(30);
	MyQueue.push(40);
	MyQueue.push(50);

	cout << "\nQueue : \n";
	MyQueue.Print();

	cout << "\n\nQueue Size = " << MyQueue.Size() << "\n";
	cout << "\nQueue Front = " << MyQueue.front() << "\n";
	cout << "\nQueue Back = " << MyQueue.back() << "\n";

	MyQueue.pop();

	cout << "\nList After pop() : \n\n";
	MyQueue.Print();

	//Extension 1
	cout << "\n\nItem (2) : " << MyQueue.GetItem(2);

	//Extension 2
	MyQueue.Reverse();
	cout << "\n\nQueue After Reverse() : \n";
	MyQueue.Print();

	//Extension 3
	MyQueue.UpdateItem(2, 600);
	cout << "\n\nQueue After Updating Item(2) to 600 : \n";
	MyQueue.Print();

	//Extension 4
	MyQueue.InsertAfter(2, 800);
	cout << "\n\nQueue After Inserting 800 After Item(2) : \n";
	MyQueue.Print();

	//Extension 5
	MyQueue.InsertAtFront(1000);
	cout << "\n\nQueue After Inserting 1000 at Front : \n";
	MyQueue.Print();

	//Extension 6
	MyQueue.InsertAtBack(2000);
	cout << "\n\nQueue After Inserting 2000 at Back : \n";
	MyQueue.Print();

	//Extension 7
	MyQueue.Clear();
	cout << "\n\nQueue After Clear() : \n";
	MyQueue.Print();

	system("pause>0");
	return 0;

}
