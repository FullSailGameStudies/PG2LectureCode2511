// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Console.h"
#include "Input.h"



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";

    std::string fileName = "2511.csv";
    std::string path = "C:/temp/2511/";
    std::string fullPath = path + fileName;
    //will NOT create the path
    //it must exists first
    // 
    //1) Open the file
    std::ofstream outFile(fullPath);
    char delimiter = '*';
    if (outFile.is_open())
    {
        //2) write to the file
        outFile << "Batman rules.";
        outFile << delimiter << 12.7 << delimiter << true;
        outFile << delimiter << 5 << delimiter << "Aquaman smells.";
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }

    //3) Close the file.
    //   GOOD PRACTICE: close it ASAP
    outFile.close();


    //1) open the file
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2) read the file
        //use getline to read 1 line from the file
        std::string line;

        //read the data from the file until 
        //it reaches a '\n' OR the end of the file (stream)
        std::getline(inFile, line);
        std::cout << line << "\n";

        //parse the line to get each piece of data
        //use std::stringstream from the sstream header
        //use getline with the stringstream to get 1 piece of data
        //at a time
        std::string data;
        std::stringstream lineStream(line);
        //read the data from the stream until 
        // it reaches a delimiter OR the end of the stream
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";

        // try-catch block
        //   put your code that MIGHT throw an exception inside of the try block

        try
        {
            double dVal;
            std::getline(lineStream, data, delimiter);
            dVal = std::stod(data);
            std::cout << dVal << "\n";

            bool bVal;
            std::getline(lineStream, data, delimiter);
            bVal = std::stoi(data);// data == "1";
            std::cout << bVal << "\n";

            int iVal;
            std::getline(lineStream, data, delimiter);
            iVal = std::stoi(data);
            std::cout << iVal << "\n";
        }
        //you can have multiple catch blocks
        //more specific catch blocks first
        catch (const std::exception& ex)
        {
            std::cout << "exception when processing " << data << "\n";
            std::cout << ex.what() << "\n";
        }
        std::getline(lineStream, data, delimiter);
        std::cout << data << "\n";
    }
    else
    {
        std::cout << fullPath << " could not be opened.\n";
    }

    //3) close the file
    inFile.close();
       

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';
}