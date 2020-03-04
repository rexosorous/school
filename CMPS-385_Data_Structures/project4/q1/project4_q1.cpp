/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 4 Part 1
    Purpose:    Evaluate a postfix expression using STACKAC.h
   ----------------------------------------------- */



#include <iostream>
#include <string>
#include "STACKPAC.h"



// function prototytpes
std::string getInput();
float calculate(char op, float a, float b);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    STACK<float, 10> s;
	std::string expression = getInput();

    for (char c : expression)
    {
        if (isdigit(c))
        {
            s.push(float(c-'0'));
        }
        else
        {
            float a = s.pop();
            float b = s.pop();
            float result = calculate(c, a, b);
            s.push(result);
        }
    }

    std::cout << expression << " = " << s.pop() << std::endl;

	system("pause");
	return 0;
}



std::string getInput()
{
    /*  name:       getINput
        input:      N/A
        output:     string
        purpose:    get the postix expression (input) from the user */
    std::string expression;
    std::cout << "Enter a postfix expression: ";
    std::cin >> expression;
    return expression;
}



float calculate(char op, float a, float b)
{
    /*  name:       calculate
        input:      char op, float a, float b
        output:     float
        purpose:    performs math operations dependent on operator
                    and returns the result of a, b */
    if (op == '+') return b + a;
    else if (op == '-') return b - a;
    else if (op == '*') return b * a;
    else if (op == '/') return b / a;
}