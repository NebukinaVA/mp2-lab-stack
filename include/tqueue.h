#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <iostream>
#include "tstack.h"

using namespace std;

// ОЧЕРЕДЬ
template <class ValType>
class TQueue : public TStack<ValType>
{
	TStack<ValType> In, Out;
	int InBot;       //индекс нижнего элемента стека In
public:
	TQueue(int s = 6);
	~TQueue();
	void Pop();                         // убрать элемент
	void Push(ValType elem);            // добавить элемент 
	bool operator==(const TQueue &q);   // сравнение
	bool operator!=(const TQueue &q);   // сравнение
	ValType operator[](int pos);
};

template <class ValType>
TQueue<ValType>::TQueue(int s)
{
	TStack <ValType> temp(s);
	In = temp;
	Out = temp;
	InBot = 0;
}

template <class ValType>
TQueue<ValType>::~TQueue()
{
}

template <class ValType>
void TQueue<ValType>::Pop()
{
	if (Out.IsEmpty())
	{
		Out = In.LoadStack();
		Out.ChangeTopElem(-InBot);
	}
	Out.Pop();
	InBot++;
}

template <class ValType>
void TQueue<ValType>::Push(ValType elem)
{
	In.Push(elem);
	Out.Clear();
}

template <class ValType>
bool TQueue<ValType>::operator==(const TQueue &q) //сравнение
{
	if ((!q.In.IsEmpty()) && (!In.IsEmpty()))
		if (In == q.In) return true;
	if ((!q.Out.IsEmpty()) && (!Out.IsEmpty()))
		if (Out == q.Out) return true;
	return false;
}

template <class ValType>
bool TQueue<ValType>::operator!=(const TQueue &q) //сравнение
{
	if (q == *this) return false;
	return true;
}

template <class ValType>
ValType TQueue<ValType>::operator[](int pos)
{
	if (Out.IsEmpty()) return In[pos + InBot];
	return Out[pos];
}


#endif
