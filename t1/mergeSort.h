#include <stdlib.h> 

#pragma once

void 
merge(int* a, size_t lengthA, int* b, size_t lengthB, int* rez, size_t lengthRez);

int* 
mergeLI(long int* a, size_t lengthA, int* b, size_t lengthB, size_t* lengthRez);

int* 
mergeLL(long int* a, size_t lengthA, long int* b, size_t lengthB, size_t* lengthRez);