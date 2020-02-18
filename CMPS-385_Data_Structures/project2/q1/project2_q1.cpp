/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 2 Part 1
    Purpose:    Read a positive integer number and convert it
    			to base 2, 8, and 16 using stack
   ----------------------------------------------- */



#include <iostream>



// our stack class
class Stack
{
private:
	char contents[100];
	int counter = 0;
public:
	void clear() { counter = 0; }
	bool isEmpty() { return (counter == 0) ? true : false; }
	bool isFull() { return (counter == 100) ? true : false; }
	void push(char c) { contents[counter++] = c; }
	char pop() { return contents[--counter]; }
};



// function prototytpes
int getInput();
Stack changeBase(int base10, int newBase);
void displayStack(Stack src);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

	// variables
	int input = getInput();
	Stack base2 = changeBase(input, 2);
	Stack base8 = changeBase(input, 8);
	Stack base16 = changeBase(input, 16);

	std::cout << "\t" << input << " at base 2 is\t";
	displayStack(base2);

	std::cout << "\t" << input << " at base 8 is\t";
	displayStack(base8);

	std::cout << "\t" << input << " at base 16 is\t";
	displayStack(base16);

	system("pause");
	return 0;
}



int getInput()
{
    /*  name:       main
        input:      N/A
        output:     string input
        purpose:    prompts and returns a int entered by the user */

	int input;
	std::cout << "Enter a postiive int number: ";
	std::cin >> input;
	return input;
}



Stack changeBase(int base10, int newBase)
{
    /*  name:       changeBase
        input:      int base10
        output:     Stack converted
        purpose:    converts a base10 number to any base using stacks */

	Stack converted;
	while (base10 > 0)
	{
		int digit = base10 % newBase;
		char fixedDigit = char('0' + digit);
		if (digit >= 10) { fixedDigit += 7; }
		converted.push(fixedDigit);
		base10 /= newBase;
	}
	return converted;
}



void displayStack(Stack src)
{
    /*  name:       displayStack
        input:      string msg, Stack src
        output:     N/A
        purpose:    displays the contents of a stack without changing it */

	while (!src.isEmpty()) { std::cout << src.pop(); }
	std::cout << std::endl;
}
