/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 2 Part 2
    Purpose:    Store 10 random integers <100 in stack S.
    			(i) 	display all numbers
    			(ii) 	copy all even numbers in stack EVEN
    					and all odd numbers in stack ODD
    			(iii)	display stack EVEN and ODD
   ----------------------------------------------- */



#include <iostream>
#include <time.h>
#include <string>



// our stack class
class Stack
{
private:
	int contents[10];
	int counter = 0;
public:
	void clear() { counter = 0; }
	bool isEmpty() { return (counter == 0) ? true : false; }
	bool isFull() { return (counter == 10) ? true : false; }
	void push(int n) { contents[counter++] = n; }
	int pop() { return contents[--counter]; }
};



// function prototytpes
void fillStack(Stack& S);
void sortStacks(Stack src, Stack& even, Stack& odd);
void displayStack(std::string msg, Stack src);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

	// variables
	Stack EVEN;
	Stack ODD;
	Stack S;

	fillStack(S); // fill S with random integers < 100
	displayStack("All Numbers:\t", S); // display all numbers
	sortStacks(S, EVEN, ODD); // sort S contents into even and odd
	displayStack("Even Numbers:\t", EVEN); // display all even numbers
	displayStack("Odd Numbers:\t", ODD); // dispaly all odd numbers

	system("pause");
	return 0;
}



void fillStack(Stack& S)
{
    /*  name:       fillStack
        input:      Stack S
        output:     Stack S
        purpose:    fills the stack with 10 random integers < 100 */

	srand(time(0));
	for (int i = 0; i < 10; ++i)
	{
		S.push(rand()%100);
	}
}



void sortStacks(Stack src, Stack& even, Stack& odd)
{
    /*  name:       sortStacks
        input:      Stack src, Stack even, Stack odd
        output:     Stack even, Stack odd
        purpose:    sorts src contents into even and odd */

	while(!src.isEmpty())
	{
		int n = src.pop();
		if (n % 2 == 0) { even.push(n); }
		else { odd.push(n); }
	}
}



void displayStack(std::string msg, Stack src)
{
    /*  name:       displayStack
        input:      string msg, Stack src
        output:     N/A
        purpose:    displays the contents of a stack without changing it */

	std::cout << msg;
	while (!src.isEmpty()) { std::cout << src.pop() << '\t'; }
	std::cout << std::endl;
}