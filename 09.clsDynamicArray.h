#pragma once

#include <iostream>
using namespace std;

template <class T>

class clsDynamicArray
{
protected:

	int _Size = 0;
	T* _TempArray;

public:

	T* OriginalArray; //Public Variable/Member Global Variable

	clsDynamicArray(int Size = 0) //Constractor (bina2)
	{
		if (Size < 0) //It's Not Possible To A Size Be In Minus
			Size = 0;

		_Size = Size;

		OriginalArray = new T[_Size]; //Memory Allocation Of Number Of T

	}

	~clsDynamicArray() //Destractor (Tadmir) it's the last method called in the object (just 1 in class)
	{
		delete[] OriginalArray; //OriginalArray memory is released
	}

	bool SetItem(int Index, T Value)
	{
		if (Index < 0 || Index >= _Size)
			return false;

		*(OriginalArray + Index) = Value; //(OriginalArray + Index) : Reference
		return true;

	}

	bool IsEmpty()
	{
		return (_Size == 0);
	}

	int Size()
	{
		return _Size;
	}

	void Resize(int NewSize)
	{
		if (NewSize < 0)
		{
			NewSize = 0;
		}

		_TempArray = new T[NewSize]; //Memory Allocation Of Number Of T

		if (NewSize < _Size)
		{
			_Size = NewSize;
		}

		for (int i = 0; i < _Size; i++)
		{
			*(_TempArray + i) = *(OriginalArray + i);
		}

		_Size = NewSize;

		delete[] OriginalArray;

		OriginalArray = _TempArray;
	}

	T GetItem(int Index)
	{
		return OriginalArray[Index];
	}

	void Reverse()
	{
		_TempArray = new T[_Size];

		for (int i = 0; i < _Size; i++)
		{
			_TempArray[i] = OriginalArray[_Size - 1 - i];
		}

		delete[] OriginalArray;

		OriginalArray = _TempArray;

	}

	void Clear()
	{
		_Size = 0;
		_TempArray = new T[0];
		delete OriginalArray;
		OriginalArray = _TempArray;
	}

	bool DeleteItemAt(T Index)
	{
		if (Index < 0 || Index >= _Size)
		{
			return false;
		}

		_Size--;
			
		_TempArray = new T[_Size];

		//Copy All Before Index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];	
		}

		//Copy All After Index
		for (int i = Index + 1; i < _Size + 1; i++)
		{
			_TempArray[i - 1] = OriginalArray[i];
		}

		delete OriginalArray;

		OriginalArray = _TempArray;

		return true;

	}

	void DeleteFirstItem()
	{
		DeleteItemAt(0);
	}

	void DeleteLastItem()
	{
		DeleteItemAt(_Size - 1);
	}

	int Find(T Value)
	{
		for (int i = 0; i < _Size; i++)
		{
			if (Value == OriginalArray[i])
			{
				return i;
			}
		}

		return -1;
	}

	bool DeleteItem(T Value)
	{
		int Index = Find(Value);

		if (Index == -1)
		{
			return false;
		}

		DeleteItemAt(Index);
		return true;
	}

	bool InsertAt(int Index, T Value)
	{
		if (Index < 0 || Index > _Size)
			return false;
		
		_Size++; 

		_TempArray = new T[_Size];

		//Copy All Before Index
		for (int i = 0; i < Index; i++)
		{
			_TempArray[i] = OriginalArray[i];
		}

		_TempArray[Index] = Value;

		//Copy All After Index
		for (int i = Index ; i < _Size - 1; i++) 
		{
			_TempArray[i + 1] = OriginalArray[i];
		}

		delete OriginalArray;

		OriginalArray = _TempArray;

		return true;

	}

	void InsertAtBeginning(T Value)
	{
		InsertAt(0, Value); //After Hearing Teacher That The Solution Is Just One Line Of Code :-)
	}

	bool InsertBefore(int Index, T Value)
	{
		if (Index < 1)
		    return InsertAt(0, Value);
		else
			return InsertAt(Index - 1, Value);
	}

	bool InsertAfter(int Index, T Value)
	{
		if (Index >= _Size)
			return InsertAt(_Size - 1, Value);
		else
		    return InsertAt(Index + 1, Value);
	}

	bool InsertAtEnd(T Value)
	{
		return InsertAt(_Size, Value);
	}

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << *(OriginalArray + i) << "   ";
		}
	}



};

//void InsertAfter(int Index, T Value)
//{
//	++Index;
//	InsertAt(Index, Value);
//}

//void InsertBefore(int Index, T Value)
//{
//	InsertAt(Index, Value);
//}

//void DeleteItemAt(T Index)
//{
//	_TempArray = new T[_Size - 1];
//
//	for (int i = 0; i < _Size; i++)
//	{
//		if (i == Index)
//		{
//			_TempArray[Index] = OriginalArray[Index + 1];
//		}
//
//		else if (i == Index + 1)
//		{
//			_TempArray[i] = OriginalArray[i + 1];
//		}
//
//		else
//		{
//			_TempArray[i] = OriginalArray[i];
//		}
//
//	}
//
//	delete OriginalArray;
//
//	OriginalArray = _TempArray;
//
//	_Size--;
//
//}

//void Clear()
//{
//	_Size = 0;
//	OriginalArray = NULL;
//	delete[] OriginalArray;
//}

//T GetItem(int Index)
//{
//	if (Index < 0 || Index >= _Size)
//	{
//		return NULL;
//	}
//
//	for (int i = 0; i < _Size; i++)
//	{
//		if (i == Index)
//		{
//			return OriginalArray[i];
//		}
//	}
//}

/*void Resize(int NewSize)
	{
		_Size = NewSize;

		for (int i = 0; i < _Size; i++)
		{
			SetItem(i, *(OriginalArray + i));
		}
	}*/