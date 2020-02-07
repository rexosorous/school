/* -----------------------------------------------
    Name:       J-Zach Loke
    Course:     CMPS-385
    Semester:   Spring 2020
    Project:    No. 1 Part 1
    Purpose:    To learn and implement structs, file i/o,
                function overloading, and basic array traversal
   ----------------------------------------------- */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>



// structs
struct PERSON
{
    std::string name;
    int age;
    float gpa;
};

// global constants
const int ARRAY_LENGTH = 6;



// function prototypes
void CopyData(std::string filename, PERSON arr[]);
void Display(PERSON arr[]);
void Display(float AgeAve, float GpaAve);
void Display(PERSON arr[], float GpaAve);
void ComputeAverage(PERSON arr[], float& AgeAve, float& GpaAve);



int main()
{
    /*  name:       main
        input:      N/A
        output:     N/A
        purpose:    main function to drive the program */

    // constants
    const std::string FILENAME = "data.txt";

    // input variables
    PERSON a[ARRAY_LENGTH];

    // output variables
    float AgeAve, GpaAve;

    CopyData(FILENAME, a);
    Display(a);
    ComputeAverage(a, AgeAve, GpaAve);
    Display(AgeAve, GpaAve);
    Display(a, GpaAve);

    system("pause");
    return 0;
}



void CopyData(std::string filename, PERSON arr[])
{
    /*  name:       CopyData
        input:      string filename
        output:     array arr
        purpose:    copies data from file into array arr */

    // setup the file stream
    std::fstream file;
    file.open(filename, std::ios::in);

    // copy data into struct array
    for(int i = 0; i < ARRAY_LENGTH; ++i)
    {
        file >> arr[i].name >> arr[i].age >> arr[i].gpa;
    }
}



void ComputeAverage(PERSON arr[], float& AgeAve, float& GpaAve)
{
    /*  name:       ComputeAverage
        input:      array arr
        output:     float AgeAve, float GpaAve
        purpose:    computes both the age and gpa averages of all the students in the array */

    float ageTotal = 0, gpaTotal = 0;

    for(int i = 0; i < ARRAY_LENGTH; ++i)
    {
        ageTotal += float(arr[i].age);
        gpaTotal += arr[i].gpa;
    }

    AgeAve = ageTotal/float(ARRAY_LENGTH);
    GpaAve = gpaTotal/float(ARRAY_LENGTH);
}



void Display(PERSON arr[])
{
    /*  name:       Display
        input:      array arr
        output:     N/A
        purpose:    displays the names of all the teenagers */

    std::cout << "Names of all the teenagers: ";
    for(int i = 0; i < ARRAY_LENGTH; ++i)
    {
        if(arr[i].age >= 13 && arr[i].age <= 19)
        {
            std::string ending = i < 5 ? ", " : "\n"; // makes sure the output is separated by commas, but doesn't end in one
            std::cout << arr[i].name << ending;
        }
    }
    std::cout << std::endl << std::endl;;
}



void Display(float AgeAve, float GpaAve)
{
    /*  name:       Display
        input:      float AgeAve, float GpaAve
        output:     N/A
        purpose:    displays the both the age and gpa averages */

    std::cout << std::showpoint << std::setprecision(2) << std::fixed;
    std::cout << "Age Average:\t" << AgeAve << std::endl;
    std::cout << "GPA Average:\t" << GpaAve << std::endl;
    std::cout << std::endl;
}



void Display(PERSON arr[], float GpaAve)
{
    /*  name:       Display
        input:      array arr, float GpaAve
        output:     N/A
        purpose:    displays the name, age, and gpa of students who
                    have gpa's higher than the average */

    std::cout << "Displaying students with above average GPA:" << std::endl;
    std::cout << "Name\tAge\tGPA" << std::endl;
    for(int i = 0; i < ARRAY_LENGTH; ++i)
    {
        if(arr[i].gpa > GpaAve)
        {
            std::cout << arr[i].name << '\t' << arr[i].age << '\t' << arr[i].gpa << std::endl;
        }
    }
    std::cout << std::endl;
}