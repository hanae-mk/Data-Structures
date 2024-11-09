#pragma once

#include <iostream>
using namespace std;

template <class T>

class clsDynamicArray
{
protected:

	int _Size = 0;
	
public:

	T* OriginalArray; //Public Variable/Member

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

	void PrintList()
	{
		for (int i = 0; i < _Size; i++)
		{
			cout << *(OriginalArray + i) << "   ";
		}
	}

	
};

