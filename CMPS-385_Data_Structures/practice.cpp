#include <iostream>
#include "stackClass.h"

/* given: stack s is initialized with integers "3, 5, 9, 2"
display the last element in the stack, while leaving the stack unchanged */


STACK<int, 4> init()
{
	STACK<int, 4> s;
	s.clear();
	int input[] = {3, 5, 9, 2};

	for (int i = 0; i < 4; ++i)
	{
		s.push(input[i]);
	}

	return s;
}


int main()
{
	// init
	STACK<int, 4> s = init();

	// solution
	STACK<int, 4> temp;
	temp.clear();
	while (!s.isEmpty())
	{
		temp.push(s.pop());
	}
	int last = temp.pop();
	s.push(last);
	std::cout << last << std::endl;
	while (!s.isFull())
	{
		s.push(temp.pop());
	}



	system("pause");
	return 0;
}