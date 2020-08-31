/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 9 Part 1
    Purpose:    Write a program to insert the name of the months from "JAN" to "DEC"
                in a Hash table of size 5
                a. Display the hash table
                b. Ask the user to enter a month name, then display the month name
                   followed by the number of days in that month
   ----------------------------------------------- */



#include <iostream>
#include <string>



class HASH
{
private:
    struct node
    {
        std::string month;
        int days;
        node *next;
    };
    node *H[5];
public:
    void init()
    {
        for (int i = 0; i < 5; ++i)
        {
            H[i] = NULL;
        }
    }

    int hashFun(std::string name)
    {
        // given definition
        return (int(name[0]) + int(name[1]) + int(name[2])) % 5;
    }

    void insert(std::string x, int n)
    {
        int index = hashFun(x);
        node *p = new(node);
        p->month = x;
        p->days = n;
        p->next = H[index];
        H[index] = p;
    }

    void display()
    {
        for (int i = 0; i < 5; ++i)
        {
            std::cout << "H[" << i << "]-->\t";
            node *p = H[i];
            while (p != NULL)
            {
                std::cout << "(" << p->month << ", " << p->days << ") -->\t";
                p = p->next;
            }
            std::cout << "NULL" << std::endl;
        }
    }

    int search(std::string x)
    {
        int index = hashFun(x);
        node *p = H[index];
        while (p != NULL && p->month != x)
        {
            p = p->next;
        }

        if (p == NULL)
        {
            return -1;
        }

        return p->days;
    }
};



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    // given
    std::string months[12] = {"JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"};
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    HASH calendar = HASH();
    for (int i = 0; i < 12; ++i)
    {
        calendar.insert(months[i], days[i]);
    }

    // part a
    calendar.display();

    // part b
    std::string input;
    std::cout << "Enter a month: ";
    std::cin >> input;
    int d = calendar.search(input);
    if (d == -1)
    {
        std::cout << "That is not a valid month." << std::endl;
    }
    else
    {
        std::cout << "That month has " << d << " days in it." << std::endl;
    }

    system("pause");
    return 0;
}