#pragma once

#include <iostream>
#include "clsMyQueueArr.h"

using namespace std;
template <class T>

class clsMyStackArr : public clsMyQueueArr <T>
{
public:

	void push(T Item)
	{
		clsMyQueueArr <T>::_MyList.InsertAtBeginning(Item);
	}

};

