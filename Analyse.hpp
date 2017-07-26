//
//  Analyse.hpp
//  Analyse
//
//  Created by cagatay arslan on 26/07/2017.
//  Copyright © 2017 cagatay arslan. All rights reserved.
//

#ifndef Analyse_hpp
#define Analyse_hpp

#pragma once

#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;



class cAnalyse {
private:
    fstream inFile,outFile;
    int count, sum;
    float average;
    char *buffer;
    const int bufferSize = 256;                 // buffer size for memory allocations
    int stringToNumber (char *,long *);          // atoa implementation with error control
    
public:
    cAnalyse();       // Constructor
    ~cAnalyse();      // Destructor
    
// Analyse function definition
// input : input file path
// output : output file path
    int analyse (const char * input, const char * output);
};
#endif /* Analyse_hpp */
