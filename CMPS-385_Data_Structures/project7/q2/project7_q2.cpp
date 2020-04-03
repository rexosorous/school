/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 7 Part 2
    Purpose:    Create a text file of sorted names using linked lists.
   ----------------------------------------------- */



#include <iostream>
#include <string>
#include <fstream>



class OrderedList
{
private:
    struct node
    {
        std::string val;
        node *next;
    };
    node *list;
public:
    OrderedList() { list = NULL; }

    void push(std::string x)
    {
        /*  name:       push
            input:      std::string x
            output:     N/A
            purpose:    adds an element into the linked list stack and makes sure to keep it ordered. */
        // create the node element we wish to insert
        node *insert = new(node);
        insert->val = x;

        // temporary variables to help traversal
        node *prev = list; // represents the node we've previously examined (needed because we can't traverse backwards).
        node *curr = list; // represents the current node we're examining.

        while (true)
        {
            // determines where in the list to insert the new node.
            if (curr == NULL)
            {
                // executes if we've reached the end of the list.
                // if this executes, that means all nodes in the list have a smaller value than the node we're inserting.
                // in this case, we should append the new node to the end of the list.
                // also executes if the list is empty (ie. the first element is NULL)
                if (list == NULL) { list = insert; }
                else { prev->next = insert; }
                insert->next = NULL;
                return;
            }
            else if (curr->val.compare(insert->val) > 0)
            {
                // executes if the node we're examining has a value larger than the node we're inserting.
                // if this executes, that means we've found the correct place to insert the new node.
                if (prev == curr) { list = insert; }
                else { prev->next = insert; }
                insert->next = curr;
                return;
            }

            // executes when we haven't found the correct place to insert the new node.
            prev = curr;
            curr = curr->next;
        }
    }

    std::string pop()
    {
        /*  name:       pop
            input:      N/A
            output:     std::string
            purpose:    removes and returns the smallest valued element from the linked list stack */
        node *p = list;
        std::string value = p->val;
        list = p->next;
        return value;
    }

    bool isEmpty()
    {
        /*  name:       isEmpty
            input:      N/A
            output:     bool
            purpose:    determines if the linked list stack is empty */
        return (list == NULL) ? true : false;
    }

    void display()
    {
        /*  name:       display
            input:      N/A
            output:     N/
            purpose:    prints the contents of the list */
        node *p = list;
        while (p != NULL)
        {
            std::cout << p->val << std::endl;
            p = p->next;
        }
    }
};



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    OrderedList presidents = OrderedList();

    // given input file
    std::fstream file;
    file.open("input.txt", std::ios::in);
    while (!file.eof())
    {
        std::string name;
        file >> name;
        presidents.push(name);
    }

    presidents.display();

    system("pause");
    return 0;
}