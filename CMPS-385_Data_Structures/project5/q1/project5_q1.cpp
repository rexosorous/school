/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 5 Part 1
    Purpose:    Linked Lists
   ----------------------------------------------- */



#include <iostream>



class LinkedList
{
private:
    // given node definition
    struct node
    {
        int age;
        node *next;
    };
    node *list;
public:
    LinkedList() { list = NULL; }

    void push(int x)
    {
        /*  name:       push
            input:      int x
            output:     N/A
            purpose:    adds an element into the linked list stack */
        node *p = new(node);
        p->age = x;
        p->next = NULL;
        if (list != NULL)
        {
            node *n = list;
            while (n->next != NULL)
            {
                n = n->next;
            }
            n->next = p;
        }
        else
        {
            list = p;
        }
    }

    int pop()
    {
        /*  name:       pop
            input:      N/A
            output:     int
            purpose:    removes and returns an element from the linked list stack */
        node *p = list;
        int value = p->age;
        list = p->next;
        return value;
    }

    bool isEmpty()
    {
        /*  name:       isEmpty
            input:      N/A
            output:     bool
            purpose:    determins if the linked list stack is empty */
        return (list == NULL) ? true : false;
    }
};





int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    int Age[5] = {19, 21, 17, 22, 33}; // given array definition

    // 1a. Construct a linked list to hold the data in array Age
    LinkedList ageStack;
    for (int x: Age)
    {
        ageStack.push(x);
    }


    // 1b. Display the linked list
    LinkedList tempStack; // used later for 1c
    while (!ageStack.isEmpty())
    {
        int val = ageStack.pop();
        std::cout << val << '\t';
        tempStack.push(val);
    }
    std::cout << std::endl;


    // 1c. Compute and display the average of numbers in the new linked list
    int ageTotal = 0;
    int eleCount = 0;
    while (!tempStack.isEmpty())
    {
        int val = tempStack.pop();
        ageTotal += val;
        eleCount++;
        ageStack.push(val); // used later for 1d
    }
    float avg = float(ageTotal)/float(eleCount);
    std::cout << "The average age is " << avg << std::endl;


    // 1d. Determine how many data in the linked list is above age average
    int avgCount = 0;
    while (!ageStack.isEmpty())
    {
        int val = ageStack.pop();
        if (val > avg)
        {
            avgCount++;
        }
    }
    std::cout << "There are " << avgCount << " people whose age are above average age" << std::endl;






    system("pause");
    return 0;
}