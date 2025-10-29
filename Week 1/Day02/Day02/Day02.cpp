#include <iostream>
#include <string>
#include <vector>
#include <Console.h>
#include "FullSailCourse.h"

bool postFix(std::string& hero)
{
    srand((unsigned int)time(NULL));
    int postFixNumber = rand() % 1000;
    hero = hero + "-" + std::to_string(postFixNumber);
    return postFixNumber % 2 == 0;
}

float average(const std::vector<int>& scores)
{
    //scores.push_back(5); //not allowed because it is marked as const
    float sum = 0;
    for (auto score : scores)
        sum += score;

    return sum / scores.size();
}

void print(const std::vector<int>& scores)
{
    std::cout << "----SCORES----\n";
    int index = 1;
    for (int score : scores)
        std::cout << index++ << ". " << score << "\n";
}

void printInfo(const std::vector<int>& scores)
{
    std::cout << "size: " << scores.size() << "\tcapacity: " << scores.capacity() << "\n";
}

//copies are "expensive"
//creating a new variable and copying one value to it
void PrintMe(int n)//Pass-by-value (COPY)
{
    std::cout << n;
}
//should I mark it const?
// does the method need to change it? if no, then use 'const'

//use pass-by-reference (ALIAS)
// prevents a copy (performs better)
// when do we use it?
//   1)when the parameter is a class
//   2)when you need to change the variable in another scope
void PrintMe(const std::string& message)
{
    Console::WriteLine(message, ConsoleColor::Green);
}
void Incrementer(int& num)//NO COPIES
{
    num++;
}
//pass nums by ref to prevent a copy
//pass min and max by ref to change their values in the other scope
void MinMax(std::vector<int>& nums, int& min, int& max)
{

}

int main()
{
    std::string msg = "Hello Gotham";
    PrintMe(msg);
    PrintMe("Hello Gotham");
    int n = 5;
    int& nAlias = n;//nAlias is also n
    Incrementer(nAlias);
    PrintMe(n);//copies this 'n' to PrintMe's 'n'
    //&n means get the address-of n
    //std::cout << &n << "\n" << &nAlias << "\n";

    std::cout << n << "\t" << nAlias << "\n";
    nAlias++;
    std::cout << n << "\t" << nAlias << "\n\n\n";
    int n2 = 10;
    //after creating the reference, you cannot change
    //what variable it refers to
    nAlias = n2;//ONLY copies n2 to nAlias
    nAlias++;
    std::cout << n << "\t" << nAlias << "\t" << n2 << "\n\n\n";


    /*
        ╔══════════════════════════════╗
        ║Parameters: Pass by Reference.║
        ╚══════════════════════════════╝
        Sends the variable itself to the method. The method parameter gives the variable a NEW name (i.e. an alias)

        NOTE: if the method assigns a new value to the parameter, the variable used when calling the method will change too.
            This is because the parameter is actually just a new name for the other variable.
    */
    std::string spider = "Spiderman";
    bool isEven = postFix(spider);
    std::string evenResult = (isEven) ? "TRUE" : "FALSE";
    std::cout << spider << "\n" << "Is Even postfix? " << evenResult << "\n";


    /*
        CHALLENGE 1:

            Write a method to fill the vector of floats with grades.
            1) pass it in by reference
            2) add 10 grades to the vector

    */
    std::vector<float> grades;
    FullSailCourse pg2;
    pg2.GetGrades(grades);
    std::cout << "\n\nPG2 2511\n";
    for (int i = 0; i < grades.size(); i++)
    {
        std::cout << grades[i] << "\n";
    }
    //foreach (range-based for)
    for (float& grade : grades)
    {
        std::cout << grade << "\n";
    }
    //auto gradesIter = grades.begin();



    /*
        ╔══════════════════╗
        ║ const parameters ║
        ╚══════════════════╝
        const is short for constant. It prevents the variable from being changed in the method.

        This is the way you pass by reference and prevent the method from changing the variable.
    */
    //const means the variable cannot be changed
    const int nConst = 10;
    //nConst++;


    std::vector<int> highScores;
    for (int i = 0; i < 10; ++i)
    {
        highScores.push_back(rand() % 5000);
        printInfo(highScores);//size: ?  capacity: ?
    }
    float avg = average(highScores);



    /*
        CHALLENGE 2:

            Write a method to calculate the stats on a vector of grades
            1) create a method to calculate the min, max. 
                pass the grades vector as a const reference. Use ref parameters for min and max.
            2) call the method in main and print out the min, max.

    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        [  Removing from a vector  ]

        clear() - removes all elements from the vector
        erase(position) - removes the element at the position
        erase(starting position, ending position) - removes a range of elements. the end position is not erased.

    */
    print(highScores);

    //erase all scores < 2500

    print(highScores);



    /*
        CHALLENGE 3:

            Using the vector of grades you created.
            Remove all the failing grades (grades < 59.5).
            Print the grades.
    */





    /*
        ╔═══════════╗
        ║ vector<T> ║
        ╚═══════════╝

        
        size(): # of items that have been ADDED
        capacity(): length of the internal array
        reserve(n): presizes the internal array
    */
    std::vector<int> scores;
    scores.reserve(10); //makes the internal array to hold 10 items.

    printInfo(scores);
}