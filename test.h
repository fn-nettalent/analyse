//
//  test.h
//  Analyse
//
//  Created by cagatay arslan on 26/07/2017.
//  Copyright © 2017 cagatay arslan. All rights reserved.
//

#ifndef test_h
#define test_h

#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
    void * analyseConstructor();                            // C reference function for class constrcustor
    void analyseDestructor(void *thisClass);                // C reference function for class destrcustor
    int analyse (const char * input, const char * output);   // C reference function for analyse function
    
#ifdef __cplusplus
}
#endif

#endif /* test_h */
