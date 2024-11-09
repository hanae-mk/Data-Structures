
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>

class clsDblLinkedList
{
protected:
	int _Size = 0;

public:

	class Node
	{
	public:

		T Value = 0;
		Node* Prev = NULL;
		Node* Next = NULL;

	};

	Node* Head = NULL; //Global Pointer Head Type Class Node, He keep the value along the object life

	void InsertAtBeginning(T Value)
	{

		Node* NewNode = NULL;
		NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Prev = NULL;
		NewNode->Next = Head; //NewNode

		if (Head != NULL)
		{
			Head->Prev = NewNode;
		}

		Head = NewNode;
		_Size++;
	}

	Node* FindNode(T Value)
	{
		Node* Current = Head; //Head is always fixed we move only current pointer

		while (Current != NULL)
		{
			if (Current->Value == Value)
			{
				return Current;
			}

			Current = Current->Next;
		}

		return NULL;
	}

	void InsertAfter(Node*& Current, T Value)
	{

		Node* NewNode = NULL;
		NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = Current->Next;
		NewNode->Prev = Current;

		if (Current->Next != NULL)
		{
			Current->Next->Prev = NewNode;
		}

		Current->Next = NewNode;
		_Size++;
	}

	void InsertAtEnd(T Value)
	{

		Node* NewNode = NULL;
		NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Next = NULL;

		if (Head == NULL)
		{
			NewNode->Prev = NULL;
			Head = NewNode;
			_Size++;
			return;
		}

		Node* Current = Head;

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = NewNode;
		Current->Prev = Current;
		_Size++;
	}

	void DeleteNode(Node*& NodeToDelete)
	{
		if (Head == NULL || NodeToDelete == NULL) return;

		if (Head == NodeToDelete)
		{
			Head = NodeToDelete->Next;
		}

		if (NodeToDelete->Next != NULL)
		{
			NodeToDelete->Next->Prev = NodeToDelete->Prev;
		}

		if (NodeToDelete->Prev != NULL)
		{
			NodeToDelete->Prev->Next = NodeToDelete->Next;
		}

		_Size--;
		delete NodeToDelete;
	}

	void DeleteFirstNode()
	{

		if (Head == NULL)
		{
			return;
		}

		Node* temp = Head;
		Head = Head->Next;

		if (Head != NULL)
		{
			Head->Prev = NULL;
		}

		delete temp;
		_Size--;

	}

	void DeleteLastNode()
	{

		if (Head == NULL)
		{
			return;
		}

		if (Head->Next == NULL)
		{
			delete Head;
			Head = NULL;
			_Size--;
			return;
		}

		Node* Current = Head;

		while (Current->Next->Next != NULL)
		{
			Current = Current->Next;
		}

		Node* Temp = Current->Next;
		Current->Next = NULL;

		delete Temp;
		_Size--;

	}

	void PrintList()
	{
		Node* Current = Head; //Head is always fixed we move only current pointer

		while (Current != NULL)
		{
			cout << Current->Value << "   ";
			Current = Current->Next;
		}
	}

	int Size()
	{
		return _Size; //Size is always ready and updated it's waaaaaaaaaaaaaaaaay faster
	}

};

















