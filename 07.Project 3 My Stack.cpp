
#include <iostream>
#include "clsMyStack.h"

using namespace std;

int main()
{
	clsMyStack <int> MyStack;

	MyStack.push(10);
	MyStack.push(20);
	MyStack.push(30);
	MyStack.push(40);
	MyStack.push(50);

	cout << "\nStack \n";
	MyStack.Print();

	cout << "\n\nStack Size : " << MyStack.Size();
	cout << "\nStack Top : " << MyStack.front();
	cout << "\nStack Bottom : " << MyStack.back();

	MyStack.pop();

	cout << "\n\nStack After pop() : \n";
	MyStack.Print();

	//Extension 1
	cout << "\n\nItem (2) : " << MyStack.GetItem(1);

	//Extension 2
	MyStack.Reverse();
	cout << "\n\nStack After Reverse() : \n";
	MyStack.Print();

	//Extension 3
	MyStack.UpdateItem(2, 600);
	cout << "\n\nStack After Updating Item(2) to 600 : \n";
	MyStack.Print();

	//Extension 4
	MyStack.InsertAfter(2, 800);
	cout << "\n\nStack After Inserting 800 After Item(2) : \n";
	MyStack.Print();

	//Extension 5
	MyStack.InsertAtFront(1000);
	cout << "\n\nStack After Inserting 1000 at Front : \n";
	MyStack.Print();

	//Extension 6
	MyStack.InsertAtBack(2000);
	cout << "\n\nStack After Inserting 2000 at Back : \n";
	MyStack.Print();

	//Extension 7
	MyStack.Clear();
	cout << "\n\nStack After Clear() : \n";
	MyStack.Print();

	system("pause>0");
	return 0;


}
