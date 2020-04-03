/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 5 Part 2
    Purpose:    Linked Lists
   ----------------------------------------------- */



#include <iostream>
#include <string>
#include <fstream>



// given node definition
struct node
{
    std::string name;
    int age;
    node *next;
};



class LinkedList
{
private:
    node *list;
public:
    LinkedList() { list = NULL; }

    void push(std::string s, int x)
    {
        /*  name:       push
            input:      string s, int x
            output:     N/A
            purpose:    adds an element into the linked list stack */
        node *p = new(node);
        p->name = s;
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

    node pop()
    {
        /*  name:       pop
            input:      N/A
            output:     int
            purpose:    removes and returns an element from the linked list stack */
        node *p = list;
        node n = *p;
        list = p->next;
        return n;
    }

    bool isEmpty()
    {
        /*  name:       isEmpty
            input:      N/A
            output:     bool
            purpose:    determines if the linked list stack is empty */
        return (list == NULL) ? true : false;
    }
};





int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    LinkedList people;
    std::fstream file;
    file.open("pro5.txt", std::ios::in); // given file
    while (!file.eof())
    {
        std::string name;
        int age;
        file >> name >> age;
        people.push(name, age);
    }
    file.close();


    // 2a. Display the linked list
    // 2b. Display the name of the oldest person
    node oldest;
    oldest.age = -1;
    std::cout << "Name\tAge" << std::endl;
    std::cout << "------------" << std::endl;
    while (!people.isEmpty())
    {
        node person = people.pop();
        std::cout << person.name << '\t' << person.age << std::endl;
        if (person.age > oldest.age)
        {
            oldest = person;
        }
    }
    std::cout << "The oldest person is " << oldest.name << std::endl;






    system("pause");
    return 0;
}