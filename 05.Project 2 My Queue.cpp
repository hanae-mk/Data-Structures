
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

	system("pause>0");
	return 0;

}