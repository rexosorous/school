/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 3 Part 1
    Purpose:    Read a phrase and determine whether it is a PALINDROME
   ----------------------------------------------- */



#include <iostream>
#include "STACKPAC.h"



// function prototytpes
template<class T> T getInput();
template<class T> T reverseStack(T s);
template<class T> bool isStackEqual(T s1, T s2);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

	char cont = 'y'; // sentinel value to determine if the user wants to stop the program
	while(cont == 'y')
	{
		STACK<char, 100> s1 = getInput<STACK<char, 100>>();
		STACK<char, 100> s2 = reverseStack<STACK<char, 100>>(s1);
		if (isStackEqual(s1, s2)) { std::cout << "This statement is a PALINDROME" << std::endl; }
		else { std::cout << "This statement is NOT a PALINDROME" << std::endl; }
		std::cout << "\tCONTINUE(y/n)? ";
		std::cin >> cont;
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << std::endl << std::endl;
	}


	system("pause");
	return 0;
}



template<class T>
T getInput()
{
    /*  name:       getInput
        input:      N/A
        output:     STACK s
        purpose:    prompts and gets input from the user */

	T s;
	char c;
	std::cout << "Enter a phrase: ";
	while (c != '\n')
	{
		cin.get(c);
		if (isalpha(c)) { s.push(tolower(c)); }
	}
	return s;
}



template<class T>
T reverseStack(T s)
{
    /*  name:       main
        input:      STACK s
        output:     STACK r
        purpose:    reverses the order of a stack by using another stack */

	T r = s;
	r.clear();

	while (!s.isEmpty())
	{
		r.push(s.pop());
	}

	return r;
}



template<class T>
bool isStackEqual(T s1, T s2)
{
    /*  name:       isStackEqual
	    input:      STACK s1, STACK s2
	    output:     bool
	    purpose:    determines if two stacks are equal*/
	while (!s1.isEmpty())
	{
		if (s1.pop() != s2.pop()) { return false; }
	}

	return true;
}