#ifndef __TQUEUE_H__
#define __TQUEUE_H__

#include <iostream>
#include "tstack.h"

using namespace std;

// Î×ÅÐÅÄÜ
template <class ValType>
class TQueue :public TStack<ValType>
{
	TStack<ValType> In, Out;
public:
	TQueue(int s = 6);
	~TQueue();
	void Pop();                         // óáðàòü ýëåìåíò
	void Push(ValType elem);            // äîáàâèòü ýëåìåíò 
	bool operator==(const TQueue &q);   // ñðàâíåíèå
	bool operator!=(const TQueue &q);   // ñðàâíåíèå
};

template <class ValType>
TQueue<ValType>::TQueue(int s)
{
	TStack <ValType> temp(s);
	In = temp;
	Out = temp;
}

template <class ValType>
TQueue<ValType>::~TQueue()
{
}

template <class ValType>
void TQueue<ValType>::Pop()
{
	if (!In.IsEmpty())
		Out = In.LoadStack();
	Out.Pop();
	In.Clear();
}

template <class ValType>
void TQueue<ValType>::Push(ValType elem)
{
	if (!Out.IsEmpty())
		In = Out.LoadStack();
	In.Push(elem);
	Out.Clear();
}

template <class ValType>
bool TQueue<ValType>::operator==(const TQueue &q) //ñðàâíåíèå
{
	if ((!q.In.IsEmpty()) && (!In.IsEmpty()))
		if (In == q.In) return true;
	if ((!q.Out.IsEmpty()) && (!Out.IsEmpty()))
		if (Out == q.Out) return true;
	return false;
}

template <class ValType>
bool TQueue<ValType>::operator!=(const TQueue &q) //ñðàâíåíèå
{
	if (q == *this) return false;
	return true;
}

#endif
