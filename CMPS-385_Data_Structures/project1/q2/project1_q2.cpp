/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 1 Part 2
    Purpose:    To learn and implement function templates
   ----------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>



// function prototypes
template <class T1> void displayArray(T1 arr, int length);
template <class T2> void sortArray(T2 arr, int length);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    // given variables
    int a[6] = {44, 55, 22, 88, 33, 11};
    std::string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    char vowels[5] = {'E', 'U', 'A', 'I', 'O'};

    std::cout << "Original array a:\t";
    displayArray(a, 6);
    sortArray(a, 6);
    std::cout << "Sorted array a  :\t";
    displayArray(a, 6);

    std::cout << std::endl;

    std::cout << "Original array month:\t";
    displayArray(months, 12);
    sortArray(months, 12);
    std::cout << "Sorted array month :\t";
    displayArray(months, 12);

    std::cout << std::endl;

    std::cout << "Original array vowel:\t";
    displayArray(vowels, 5);
    sortArray(vowels, 5);
    std::cout << "Sorted array vowel : \t";
    displayArray(vowels, 5);

    std::cout << std::endl;

    system("pause");
    return 0;
}



template <class T1>
void displayArray(T1 arr, int length)
{
    /*  name:       display array
        input:      array arr, int length
        output:     N/A
        purpose:    displays an array regardless of data type */

    for(int i = 0; i < length; ++i)
    {
        std::cout << arr[i] << '\t';
    }
    std::cout << std::endl;
}



template <class T2>
void sortArray(T2 arr, int length)
{
    /*  name:       arraySort
        input:      array arr, int length
        output:     N/A
        purpose:    sorts an array regardless of data type */

    std::sort(arr, arr + length);
}