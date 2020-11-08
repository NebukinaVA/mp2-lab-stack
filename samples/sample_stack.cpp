#include <iostream>
#include "tstack.h"

bool StringIsCorrect(string s)
{
	TStack<char> stack;
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
			stack.Push(s[i]);
		else if ((!stack.IsEmpty()) && (stack.GetTop() == '(') && (s[i] == ')'))
			stack.Pop();
		else if ((!stack.IsEmpty()) && (stack.GetTop() == '{') && (s[i] == '}'))
			stack.Pop();
		else if ((!stack.IsEmpty()) && (stack.GetTop() == '[') && (s[i] == ']'))
			stack.Pop();
		else if ((s[i] == ')') && (stack.IsEmpty()))
			return false;
		else if ((s[i] == '}') && (stack.IsEmpty()))
			return false;
		else if ((s[i] == ']') && (stack.IsEmpty()))
			return false;
	}
	if (stack.IsEmpty()) return true;
	return false;
}

int main(int argc, char** argv)
{
	string str;
	if (argc > 1)
		str = argv[1];
	cout << StringIsCorrect(str) << endl;
	return 0;
}