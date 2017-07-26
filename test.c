//
//  test.c
//  Analyse
//
//  Created by cagatay arslan on 26/07/2017.
//  Copyright © 2017 cagatay arslan. All rights reserved.
//
// This is the test function to execute analyse C++ class function from a C code

#include "test.h"

int main(int argc, const char * argv[]) {
    printf("Analyse function for netTalent\n");

// input file is a text in text format, each line has a decimal number delimited by CR
// output file is a text file created by the function, contains count, sum and avearage values in each line

// call C function analyse to create cAnalyse object
    int i = analyse ("/Users/ca/Desktop/Analyse/analyse.txt","/Users/ca/Desktop/Analyse/result.txt");

// result : 0 succesful, -1 unsuccesful
    printf("Analyse function result is : %d\n", i);

}

