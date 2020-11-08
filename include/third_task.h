#ifndef __THIRD_TASK_H__
#define __THIRD_TASK_H__

#include <iostream>
#include "tstack.h"

using namespace std;

template <class ValType>
class StackWithMinimum
{
private:
	TStack <ValType> stack, min;
public:
	StackWithMinimum(int s = 10)
	{
		TStack <ValType> temp(s);
		stack = temp;
		min = temp;
	}
	bool IsEmpty()
	{
		return stack.IsEmpty();
	}
	bool IsFull()
	{
		return stack.IsFull();
	}
	void Push(ValType elem)
	{
		stack.Push(elem);
		if ((min.IsEmpty()) || (elem < min.GetTop()))
			min.Push(elem);
	}
	void Pop()
	{
		if (min.GetTop() == stack.GetTop())
			min.Pop();
		stack.Pop();
	}
	ValType GetMin()
	{
		if (stack.IsEmpty()) throw "Stack is empty!";
		return min.GetTop();
	}
};

#endif