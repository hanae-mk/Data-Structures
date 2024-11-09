#pragma once

#include <iostream>
#include "clsMyQueue.h"
using namespace std;

template <class T>

class clsMyStack : public clsMyQueue <T> //Base Class
{

public:

	void push(T Item) //Overriding it's same as clsmyqueue
	{
		clsMyQueue <T>::_MyList.InsertAtBeginning(Item);

		/*ممكن البعض بتسائل كيف استدعى الاستاذ الميثودس بهالشكل 
		وهم مو محطوطين ستاتيك.!فالجواب على هالنقطة هو منقدر نستدعي 
		الميثودس بهالطريقة لكن فقط من داخل الكلاس الوارث من البيز كلاس*/
	}

	/*T Top()
	{
		return clsMyQueue <T>::front();
	}

	T Bottom()
	{
		return clsMyQueue <T>::back();
	}*/

	//For Method Top and Bottom you can not write them , because they are in clsMuQueue Class 


};

