/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 8 Part 1
    Purpose:    Given a text file, write a program to insert all data into an ordered
                Linked List (based on account number).
   ----------------------------------------------- */



#include <iostream>
#include <string>
#include <fstream>



struct AccountNotFound : public std::exception
{
    // custom exception
    // thrown when a user tries to search for an account that does not exist.
    const char *msg () const throw ()
    {
        return "Could not find an account with that account number. Please Try again.";
    }
};



struct node
{
    // must be defined outside of the ordered linked list
    // to avoid scope problems
    int acc_num;
    std::string name;
    float balance;

    node *prev;
    node *next;
};



class OrderedList
{
private:
    node *list;
public:
    OrderedList() { list = NULL; }

    void push(int acc, std::string n, float bal)
    {
        /*  name:       push
            input:      int acc, string n, float bal
            output:     N/A
            purpose:    adds an element into the linked list stack and makes sure to keep it ordered. */
        // create the node element we wish to insert
        node *insert = new(node);
        insert->acc_num = acc;
        insert->name = n;
        insert->balance = bal;

        // temporary variables to help traversal
        node *curr = list; // represents the current node we're examining.

        while (true)
        {
            // determines where in the list to insert the new node.
            if (list == NULL)
            {
                // executes if the list is empty (ie. the first element is NULL)
                list = insert;
                insert->prev = NULL;
                insert->next = NULL;
                return;
            }
            else if (curr->acc_num > insert->acc_num)
            {
                // executes if the node we're examining has a value larger than the node we're inserting.
                // if this executes, that means we've found a place within the list to insert our new node into.
                if (curr->prev == NULL)
                {
                    // if we're inserting to the front of the list
                    list = insert;
                    insert->prev = NULL;
                }
                else
                {
                    insert->prev = curr->prev;
                    curr->prev->next = insert;
                }

                insert->next = curr;
                curr->prev = insert;
                return;
            }
            else if (curr->next == NULL)
            {
                // executes if we've reached the end of the list.
                // if this executes, that means all nodes in the list have a smaller value than the node we're inserting.
                // in this case, we should append the new node to the end of the list.
                insert->next = NULL;
                insert->prev = curr;
                curr->next = insert;
                return;
            }

            // executes when we haven't found the correct place to insert the new node.
            curr = curr->next;
        }
    }

    node* pop()
    {
        /*  name:       pop
            input:      N/A
            output:     node
            purpose:    removes and returns the smallest valued element from the linked list stack */
        node *p = list;
        list = p->next;
        return p;
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
            output:     N/A
            purpose:    displays each account's account number and name */
        node *p = list;
        while (p != NULL)
        {
            std::cout << '\t' << p->acc_num << ',' << p->name;
            p = p->next;
        }
    }

    node* getAccByNum(int n)
    {
        /*  name:       getAccByNum
            input:      int n
            output:     node
            purpose:    finds and returns the account node whose account number matches the input
            throws:     AccountNotFound */
        node *p = list;
        while (p != NULL)
        {
            if (p->acc_num == n)
            {
                return p;
            }
            p = p->next;
        }
        throw AccountNotFound();
    }
};



// function prototypes
OrderedList init();
void showBalance(OrderedList accounts);
void deposit(OrderedList accounts);
void withdraw(OrderedList accounts);
void showAccounts(OrderedList accounts);
void close(OrderedList accounts);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */
    OrderedList accounts = init();

    const std::string MENU = "---------------Menu-------------------\n1. Show my balance\n2. Deposit in my account\n3. Withdraw from my account\n4. Show me all\n5. Close my account\n\n";
    std::cout << MENU;

    void (*funcs[]) (OrderedList) = {showBalance, deposit, withdraw, showAccounts, close};

    char cont = 'y';
    while (cont == 'y')
    {
        int choice;
        std::cout << "Please enter your choice (1-5): ";
        std::cin >> choice;

        funcs[choice-1](accounts);

        std::cout << std::endl << "CONTINUE(y/n)? ";
        std::cin >> cont;
        std::cout << std::endl;
    }

    system("pause");
    return 0;
}



OrderedList init()
{
    /*  name:       init
        input:      N/A
        output:     OrderedList
        purpose:    inits the ordered list with data from input.txt */
    OrderedList accounts = OrderedList();

    // given input file
    std::fstream file;
    file.open("input.txt", std::ios::in);
    while (!file.eof())
    {
        int acc;
        std::string n;
        float bal;

        file >> acc >> n >> bal;
        accounts.push(acc, n, bal);
    }

    return accounts;
}



void showBalance(OrderedList accounts)
{
    /*  name:       showBalance
        input:      OrderedList accounts
        output:     N/A
        purpose:    Shows an account's balance */
    int num;
    std::cout << "\tEnter your account number: ";
    std::cin >> num;

    try
    {
        node *acc = accounts.getAccByNum(num);
        std::cout << "\t\t" << acc->name << ", your balance is " << acc->balance << std::endl;
    }
    catch (AccountNotFound& e)
    {
        std::cout << e.msg() << std::endl;
    }
}



void deposit(OrderedList accounts)
{
    /*  name:       deposit
        input:      OrderedList accounts
        output:     N/A
        purpose:    Deposits money into an account */
    int num;
    std::cout << "\tEnter your account number: ";
    std::cin >> num;

    try
    {
        node *acc = accounts.getAccByNum(num);

        float amount;
        std::cout << "\t\t" << acc->name << ", how much would you like to deposit? ";
        std::cin >> amount;

        acc->balance += amount;

        std::cout << "\t\t" << acc->name << ", your new balance is " << acc->balance << std::endl;
    }
    catch (AccountNotFound& e)
    {
        std::cout << e.msg() << std::endl;
    }
}



void withdraw(OrderedList accounts)
{
    /*  name:       withdraw
        input:      OrderedList accounts
        output:     N/A
        purpose:    Withdraws money into an account */
    int num;
    std::cout << "\tEnter your account number: ";
    std::cin >> num;

    try
    {
        node *acc = accounts.getAccByNum(num);

        float amount;
        std::cout << "\t\t" << acc->name << ", how much would you like to withdraw? ";
        std::cin >> amount;

        acc->balance -= amount;

        std::cout << "\t\t" << acc->name << ", your new balance is " << acc->balance << std::endl;
    }
    catch (AccountNotFound& e)
    {
        std::cout << e.msg() << std::endl;
    }
}



void showAccounts(OrderedList accounts)
{
    /*  name:       showAccounts
        input:      OrderedList accounts
        output:     N/A
        purpose:    Shows all accounts */
    accounts.display();
    std::cout << std::endl;
}



void close(OrderedList accounts)
{
    /*  name:       close
        input:      OrderedList accounts
        output:     N/A
        purpose:    Closes (deletes) an account */
    int num;
    std::cout << "\tEnter your account number: ";
    std::cin >> num;

    try
    {
        node *acc = accounts.getAccByNum(num);
        std::string name = acc->name;
        acc->prev->next = acc->next;
        delete acc;
        std::cout << "\t\t" << name << ", we closed your account" << std::endl;
    }
    catch (AccountNotFound& e)
    {
        std::cout << e.msg() << std::endl;
    }
}