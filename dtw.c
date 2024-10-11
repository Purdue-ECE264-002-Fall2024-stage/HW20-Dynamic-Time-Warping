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
// Reads the sequence of strings from a file
// Returns the sequence of strings
// NOTE: You may assume the sequence will never exceed 200 strings and each string will never exceed 100 characters
char ** readStringSeq(char * filename)
{
    // open the file
    FILE * file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file\n");
        return NULL;
    }

    // allocate memory for the sequence of strings (max size of 200 words)
    char ** seq = (char **)malloc(200 * sizeof(char *));
    for (int i = 0; i < 200; i++)
    {
        seq[i] = (char *)malloc(100 * sizeof(char));
    }

    int index = 0;
    while (index < 200 && fscanf(file, "%99s", seq[index]) == 1)
    {
        index++;
    }

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
// Computes the DTW accumulated cost matrix using provided sequences of strings
// Uses the Levenshtein distance to compute the cost between two strings
// Returns the DTW accumulated cost matrix
double ** computeStringDTW(char ** seq1, char ** seq2, int size1, int size2)
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
            double current_cost = Levenshtein(seq1[i - 1], seq2[j - 1]);
            double insertion_cost = distance_matrix[i-1][j];
            double deletion_cost = distance_matrix[i][j-1];
            double match_cost = distance_matrix[i-1][j-1];
            
            distance_matrix[i][j] =  current_cost + min(insertion_cost, min(deletion_cost, match_cost));
        }
    }

    return distance_matrix;
}