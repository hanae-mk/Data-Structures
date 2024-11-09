#pragma once

#include <iostream>
#include <stack>
using namespace std;

class clsMyString
{
private:

	string _Value = "";
	stack <string> _Undo;
	stack <string> _Redo;

public:

	void SetValue(string Value)  		                        
	{
		_Undo.push(_Value); //Tracking Value With Undo Stack
		_Value = Value;    //Every Time We Change Value , We Push The Previous Value
	}					   //And Update The New Value

	string GetValue()
	{
		return _Value;
	}

	__declspec(property(put = SetValue, get = GetValue)) string Value;

	void Undo()
	{
		if (!_Undo.empty())
		{
			_Redo.push(_Value);
			_Value = _Undo.top();
			_Undo.pop();
		}
	}

	void Redo()
	{
		if (!_Redo.empty())
		{
			_Undo.push(_Value);
			_Value = _Redo.top();
			_Redo.pop();
		}
	}



};


