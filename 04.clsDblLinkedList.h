
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

	bool IsEmpty()
	{
		//It's better to check the size instead of head
		return (_Size == 0) ? true : false;

		//return (Head == NULL) ? true : false; My Solution
	}

	void Clear()
	{
		while (_Size > 0)
		{
			DeleteFirstNode();
		}
		
		/*Head = NULL;
		delete Head;
		_Size = 0;*/
	}

	//void Reverse()
	//{
	//	Node* Current = Head;

	//	Node* ReverseList = new Node();
	//	ReverseList = Current;
	//	
	//	if (Current->Next == NULL) //That means there is just one node in the linked list
	//	{	
	//		return;
	//	}

	//	while (Current->Next != NULL)
	//	{	
	//		Current = Current->Next;
	//	}

	//	while (Current->Prev != NULL)
	//	{
	//		ReverseList->Value = Current->Value;
	//		ReverseList->Next = Current->Prev;
	//		Current = Current->Prev;
	//		
	//	}

	//	if (Current->Prev == NULL)
	//	{
	//		ReverseList->Value = Current->Value;
	//		
	//	}

	//	Head = ReverseList;

	//	
	//}

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

	/*Node* GetNode(int Value)
	{
		int Counter = 0;

		Node* Current = Head; 

		while (Current != NULL)
		{
			if (Counter == Value)
			{
				return Current;
			}

			Counter++;
			Current = Current->Next;
		}

		return NULL;
	}*/

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

	/*int GetItem(int Index)
	{
		if (Index > _Size - 1 || Index < 0)
		{
			return 0;
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

		return Current->Value;
	}*/

	T GetItem(T Index)
	{
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			return NULL;
		else
			return ItemNode->Value;
	}

	/*void UpdateItem(T Index, T UpdateTo)
	{
		
		Node* ItemNode = GetNode(Index);

		if (ItemNode == NULL)
			cout << "\nItem Not Found!\n";
		else
			ItemNode->Value = UpdateTo;

		Node* Head = ItemNode;

	}*/

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

	/*void InsertAfter(int Index, T Value)
	{		
		Node* ItemNode = GetNode(Index);	
		Node* NewNode = new Node();

		if (ItemNode != NULL)
		{

			NewNode->Value = Value;
			NewNode->Next = ItemNode->Next;
			NewNode->Prev = ItemNode;

			if (ItemNode->Next != NULL)
			{
				ItemNode->Next->Prev = NewNode;
			}

			ItemNode->Next = NewNode;
		}

	}*/

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

















