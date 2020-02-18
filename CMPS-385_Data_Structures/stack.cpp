#include <iostream>
#include <string>
#include "stackClass.h"

int main()
{
	int a[5] = {10, 6, 9 , 7, 2};
	STACK<int, 5> s;
	s.clearStack();

	for (int i = 0; i < 5; ++i)
	{
		s.pushStack(a[i]);
	}

	while (!s.isStackEmpty())
	{
		std::cout << s.popStack() << "\t";
	}

	system("pause");
	return 0;
}