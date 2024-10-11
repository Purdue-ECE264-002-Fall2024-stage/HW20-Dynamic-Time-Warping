// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "dtw.h"
#include "helper.h"
#define min(a,b) ((a) < (b) ? (a) : (b))

// ***
// Complete this function
// ***
// Reads the sequence of characters from a file
// Returns the character sequence
// NOTE: You may assume the character sequence will never exceed 100 characters
char * readCharSeq(char * filename)
{
    
}

// ***
// Complete this function
// ***
// Reads the sequence of strings from a file
// Returns the sequence of strings
// NOTE: You may assume the sequence will never exceed 200 strings and each string will never exceed 100 characters
char ** readStringSeq(char * filename)
{
    
}

// ***
// Complete this function
// ***
// Computes the DTW accumulated cost matrix using provided character sequences
// Returns the DTW accumulated cost matrix
// NOTE: You may wish to use the constant DBL_MAX to represent infinity
double ** computeDTW(char * seq1, char * seq2, int size1, int size2)
{

}

// ***
// Complete this function
// ***
// Computes the DTW accumulated cost matrix using provided sequences of strings
// Uses the Levenshtein distance to compute the cost between two strings
// Returns the DTW accumulated cost matrix
double ** computeStringDTW(char ** seq1, char ** seq2, int size1, int size2)
{
    
}