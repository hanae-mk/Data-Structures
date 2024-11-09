#pragma once

#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;

//QUEUE DATA STRUCTURE (REUSABILITY OF CODE)

template <class T>

class clsMyQueue /*: public clsDblLinkedList <T> Using Inheritance*/
{
protected:

	//Principle Composition In OOP(Object Inside Class type another class) 
	//It's Better In This Case Not Inheritance Because we don't need all the methods
	//And we don't want to expose all the methods in MyQueue Outside (MyQueue.) we don't want
	//To show all the methods so it's better the use composition
	clsDblLinkedList <T> _MyList; //_MyList is a global variable

public:

	//clsDblLinkedList <T> DblLinkedList;

	void push(T Item)
	{
		_MyList.InsertAtEnd(Item);
	}

	void pop()
	{
		_MyList.DeleteFirstNode();
	}

	int Size()
	{
		return _MyList.Size();
	}

	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	void Print()
	{
		_MyList.PrintList();
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);
	}

	void Reverse()
	{
		_MyList.Reverse();
	}

	void UpdateItem(int Index, T NewValue)
	{
		_MyList.UpdateItem(Index, NewValue);
	}

	void InsertAfter(int Index, T NewValue)
	{
		_MyList.InsertAfter(Index, NewValue);
	}

	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBeginning(Value);
	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);
	}

	void Clear()
	{
		_MyList.Clear();
	}

};



