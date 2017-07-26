//
//  Analyse.cpp
//  Analyse
//
//  Created by cagatay arslan on 26/07/2017.
//  Copyright © 2017 cagatay arslan. All rights reserved.
//
// Analyse class implementation
// Also includes C reference functions implementations
// Class reads numbers from input file and write results to the output file
// Output file contains three line;
//      count of the numbers
//      sum of the numbers
//      avearege of the numbers

#include "test.h"
#include "Analyse.hpp"

//******
//******   C reference functions
//******
void * analyseConstructor()
{
    return new cAnalyse();
}

void analyseDestructor(void *thisClass)
{
    delete static_cast<cAnalyse*> (thisClass);
}

int analyse ( const char * input, const char * output)
{
    void *thisClass = analyseConstructor();

    int r =  static_cast<cAnalyse*> (thisClass)->analyse(input,output);
    
    analyseDestructor(thisClass);

    return r;
}

//******
//******   C++ class implementation
//******

using namespace std;

// Class constructor
// Allocate buffers, initialize variables

cAnalyse::cAnalyse()
{
//    cout << "init\n";
    sum = count = average = 0;
    buffer = new char [bufferSize];
}

// Class destructure
// Close files and delete allocated memories
cAnalyse::~cAnalyse()
{
//    cout << "clean\n";
    inFile.close();
    outFile.close();
    delete buffer;
}

int cAnalyse::analyse (const char * input, const char * output)
{
//    cout << "initial values:" << sum  << "," << count << ","<< average << "\n";
    
    // open input file
    inFile.open(input);
    if ( (inFile.rdstate() & std::ifstream::failbit ) != 0 )
    {
        std::cerr << "Error opening:" << input << "\n";
        return -1;
    }
    // open output file
    outFile.open(output,ios::out);
    if ( (outFile.rdstate() & std::ifstream::failbit ) != 0 )
    {
        std::cerr << "Error opening:" << output << "\n";
        return -1;
    }
    while (inFile.getline(buffer , bufferSize, '\r'))    //!inFile.eof())
    {
        int value;
        int r = stringToNumber(buffer,&value);
        if (r == 0)     // valid number
        {
            count++;
            sum += value;
        }
        else
            return -1;
    }
    // if it's not EOF file, there is a reading error
    if ( (inFile.rdstate() & std::ifstream::eofbit ) == 0 )
    {
        std::cerr << "Error reading:" << input << "\n";
        return -1;
    }
    // all the lines in the file are read, avearege can be calculated now
    average = (float) sum / count;
    outFile << count << "\n" << sum << "\n" << average << "\n" ;
    return 0;
}

// string to number conversion function
// check if the string has proper decimal number
int cAnalyse::stringToNumber (char *pNumber,int *returnValue)
{
    char *p;
    long value = std::strtol(pNumber, &p, 10);
    
    if (p == pNumber)
    {
        // Not a valid number
        return -1;
    }
    else if (*p != '\0')
    {
        // String begins with a valid number, but also contains something else after the number
        return -1;
    }
    else
    {
        // String is a valid number
        *returnValue = value;
        return 0;
    }
}
