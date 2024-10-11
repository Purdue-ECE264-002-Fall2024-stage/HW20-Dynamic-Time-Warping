#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  if (strlen(str1) == 0) 
  {
    return strlen(str2);
  }

  if (strlen(str2) == 0) 
  {
    return strlen(str1);
  }

  if ((*str1) == (*str2)) // first letter same
  {
    return Levenshtein(str1 + 1, str2 + 1);
  }

  int dist1 = Levenshtein(str1 + 1, str2);
  int dist2 = Levenshtein(str1, str2 + 1);
  int dist3 = Levenshtein(str1 + 1, str2 + 1); 

  int min_dist = min(dist1, min(dist2, dist3));

  return 1 + min_dist;
}

// ***
// Complete this function
// ***
// Counts the number of elements in a sequence of strings
// Returns the number of elements
int countElements(char **seq) {
    int count = 0;
    while (seq[count] != NULL) {
        count++;
    }
    return count;
}

// ***
// Complete this function
// ***
// Frees the distance matrix data
void freeDistanceMatrix(double ** seq, int num_rows)
{
    for (int i = 0; i < num_rows; i++) {
        free(seq[i]);
    }
    free(seq);
}

// *******************************************************************************

// ***
// DO NOT MODIFY THIS FUNCTION!!
// ***
// Prints the optimal path through the accumulated cost matrix
// Outputs the path in the format: [(0, 0), (1, 1), ..., (size1-1, size2-1)]
// NOTE: size1 and size2 should be lengths of the original sequences
void printOptimalPath(double ** accum_cost_matrix, int size1, int size2)
{
    printf("Optimal path: [");
    int i = 1;
    int j = 1;

    while(i < size1 || j < size2)  // while we have not reached the final matrix piece
    {
        printf("(%d, %d), ", i - 1, j - 1);
        if(i == size1) // we have reached the end of the first sequence
        {
            j++;
        }
        else if(j == size2) // we have reached the end of the second sequence
        {
            i++;
        }
        else // we can move in any of the 3 possible directions
        {
            double min_cost = min(accum_cost_matrix[i+1][j], min(accum_cost_matrix[i][j+1], accum_cost_matrix[i+1][j+1]));
            if(min_cost == accum_cost_matrix[i+1][j])  // move down
            {
                i++;
            }
            else if(min_cost == accum_cost_matrix[i][j+1])  // move right
            {
                j++;
            }
            else  // move diagonally
            {
                i++;
                j++;
            }
        }
    }
    printf("(%d, %d)]\n", i - 1, j - 1);
}
