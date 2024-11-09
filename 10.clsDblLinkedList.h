
#pragma once
#include <iostream>
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

	Node* Head = NULL;

	void InsertAtBeginning(T Value)
	{

		Node* NewNode = NULL;
		NewNode = new Node();

		NewNode->Value = Value;
		NewNode->Prev = NULL;
		NewNode->Next = Head;

		if (Head != NULL)
		{
			Head->Prev = NewNode;
		}

		Head = NewNode;
		_Size++;
	}

	Node* FindNode(T Value)
	{
		Node* Current = Head;

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
		NewNode->Prev = Current;
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
		Node* Current = Head;

		while (Current != NULL)
		{
			cout << Current->Value << "   ";
			Current = Current->Next;
		}
	}

	int Size()
	{
		return _Size;
	}

	bool IsEmpty()
	{
		return (_Size == 0) ? true : false;
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
	}

	void Reverse()
	{
		//Same Logic As Swap Numbers
		Node* Current = Head;
		Node* Temp = nullptr;

		while (Current != nullptr)
		{
			Temp = Current->Prev;
			Current->Prev = Current->Next;
			Current->Next = Temp;
			Current = Current->Prev;

		}

		if (Temp != nullptr)
		{
			Head = Temp->Prev;
		}
	}

	Node* GetNode(int Index)
	{
		if (Index > _Size - 1 || Index < 0)
		{
			return NULL;
		}

		int Counter = 0;
		Node* Current = Head;

		while (Current != NULL && Current->Next != NULL)
		{
			if (Counter == Index)
			{
				break;
			}

			Counter++;
			Current = Current->Next;
		}

		return Current;
	}

	T GetItem(T Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->Value;
	}

	bool UpdateItem(T Index, T UpdateTo)
	{

		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			ItemNode->Value = UpdateTo;
			return true;
		}
		else
			return false;
	}

	bool InsertAfter(int Index, T Value)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode != NULL)
		{
			InsertAfter(ItemNode, Value);
			return true;
		}
		else
			return false;

	}

};
