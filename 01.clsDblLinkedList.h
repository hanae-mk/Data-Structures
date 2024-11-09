
#pragma once
#include <iostream>
using namespace std;

template <class T>

class clsDblLinkedList
{
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
			return;
		}

		Node* Current = Head; 

		while (Current->Next != NULL)
		{
			Current = Current->Next;
		}

		Current->Next = NewNode;
		Current->Prev = Current;
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

		delete NodeToDelete;
	}

	void DeleteFirstNode()
	{

		if (Head == NULL) {
			return;
		}

		Node* temp = Head;
		Head = Head->Next;

		if (Head != NULL) {
			Head->Prev = NULL;
		}

		delete temp;

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

	}

	void PrintList()
	{
		Node* Current = Head; //Head is always fixed we move only current pointer

		while (Current != NULL)
		{
			cout << Current->Value << "   ";
			Current = Current->Next;
		}

		delete Current; //Even if I didn't write delete current it's will be deleted because I didn't initialize it in memory (Node* Current = new Node())
	}

};

	

	

	

	

	




	

