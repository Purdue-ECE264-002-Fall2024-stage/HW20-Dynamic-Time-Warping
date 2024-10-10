// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <math.h>
#include <assert.h>
#include "dtw.h"
#define min(a,b) ((a) < (b) ? (a) : (b))

// ***
// Complete this function
// ***
// Reads the sequence of characters from a file
// Returns the character sequence
// NOTE: You may assume the character sequence will never exceed 100 characters
char * readCharSeq(char * filename)
{
    // open the file
    FILE * file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }

    // allocate memory for the sequence (max size of 100)
    char * seq = (char *)malloc(100 * sizeof(char));
    int index = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF && index < 100)
    {
        if(ch != ',' && ch != '\n')  // divide characters by commas
        {
            seq[index] = (char)ch;
            index++;
        }
    }
    // add the null terminator
    seq[index] = '\0';

    // Close the file
    fclose(file);
    return seq;
}

// ***
// Complete this function
// ***
// Computes the DTW accumulated cost matrix using provided character sequences
// Returns the DTW accumulated cost matrix
// NOTE: You may wish to use the constant DBL_MAX to represent infinity
double ** computeDTW(char * seq1, char * seq2, int size1, int size2)
{
    // create the distance matrix
    double ** distance_matrix = (double **)malloc((size1+1) * sizeof(double *));
    for (int i = 0; i < size1 + 1; i++)
    {
        distance_matrix[i] = (double *)malloc((size2+1) * sizeof(double));
    }

    // initialize the distance matrix - use DBL_MAX to represent infinity
    for (int i = 0; i < size1+1; i++)
    {
        for (int j = 0; j < size2+1; j++)
        {
            distance_matrix[i][j] = DBL_MAX;
        }
    }
    // set the starting point
    distance_matrix[0][0] = 0.0;

    // compute the minimum distance
    for (int i = 1; i < size1+1; i++)
    {
        for (int j = 1; j < size2+1; j++)
        {
            double current_cost = abs(seq1[i - 1] - seq2[j - 1]);
            double insertion_cost = distance_matrix[i-1][j];
            double deletion_cost = distance_matrix[i][j-1];
            double match_cost = distance_matrix[i-1][j-1];
            
            distance_matrix[i][j] =  current_cost + min(insertion_cost, min(deletion_cost, match_cost));
        }
    }

    return distance_matrix;
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
