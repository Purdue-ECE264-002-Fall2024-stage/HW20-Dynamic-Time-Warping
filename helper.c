#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include "helper.h"
#define min(a,b) ((a) < (b) ? (a) : (b))

// ***
// Complete this function
// ***
// Computes the Levenshtein distance between two strings
// Returns the Levenshtein distance
// NOTE: You may wish to review HW06 for the Levenshtein distance algorithm
int Levenshtein(const char* str1, const char* str2)
{
    
}

// ***
// Complete this function
// ***
// Counts the number of elements in a sequence of strings
// Returns the number of elements
int countElements(char **seq) 
{

}

// ***
// Complete this function
// ***
// Frees the cost matrix data
void freeCostMatrix(double ** seq, int num_rows)
{

}


// ***
// Complete this function
// ***
// Prints the optimal path through the accumulated cost matrix
// NOTE: size1 and size2 should be lengths of the original sequences
void printOptimalPath(double ** accum_cost_matrix, int size1, int size2)
{
    // Start from accum_cost_matrix[size1][size2] and find the shortest path to (0, 0)
    // Print shortest path in the format: [(0, 0), (1, 1), ..., (size1, size2)] - reverse order
    // Find the smallest cell between the left, top and diagonally left cell
    // The precedence for breaking a tie is diagonally left > top > left
    
}
