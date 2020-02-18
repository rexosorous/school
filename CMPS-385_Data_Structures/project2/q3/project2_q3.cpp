/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 2 Part 3
    Purpose:    Read a sentence and display all lowercase letters,
    			uppercase letters, and vowels in reverse order as you read.
    			Use predefined fucntions: isupper, islower, and wirte your own
    			functions isVowel
   ----------------------------------------------- */



#include <iostream>
#include <string>



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
std::string getInput();
bool isVowel(char c);
void displayStack(std::string msg, Stack src);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

	// variables
	Stack upper;
	Stack lower;
	Stack vowel;
	std::string input = getInput();

	// sort the string
	for (std::string::size_type i = 0; i < input.size(); ++i)
	{
		char c = input[i];
		if (islower(c) && !lower.isFull()) { lower.push(c); }
		if (isupper(c) && !upper.isFull()) { upper.push(c); }
		if (isVowel(c) && !vowel.isFull()) { vowel.push(c); }
	}

	// output
	displayStack("Uppercase letters:\t", upper);
	displayStack("Lowercase letters:\t", lower);
	displayStack("Vowels:\t\t\t", vowel);

	system("pause");
	return 0;
}



std::string getInput()
{
    /*  name:       main
        input:      N/A
        output:     string input
        purpose:    prompts and returns a sentence entered by the user */

	std::string input;
	std::cout << "Enter a sentence: ";
	std::getline(std::cin, input);
	return input;
}



bool isVowel(char c)
{
    /*  name:       isVowel
        input:      char c
        output:     bool
        purpose:    determines if a character is a vowel regardless of case */

    c = tolower(c); // convert to lowercase
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? true : false;
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