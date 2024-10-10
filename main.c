// ***
// *** Do NOT modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dtw.h"

int main(int argc, char ** argv)
{
    if (argc != 6)
    {
        printf("Usage: ./hw20 <filename1> <filename2> <filename3> <filename4> <filetype>\n");
        return EXIT_FAILURE;
    }

    char * file1 = argv[1];
    char * file2 = argv[2];
    char * file3 = argv[3];
    char * file4 = argv[4];
    char * filetype = argv[5];

    // Read the sequences from the files for characters and integers
    if(strcmp(filetype, "CHAR") == 0 || strcmp(filetype, "INT") == 0)
    {
        // Read in the sequences
        char * seq1 = readCharSeq(file1);
        char * seq2 = readCharSeq(file2);
        char * seq3 = readCharSeq(file3);
        char * seq4 = readCharSeq(file4);
        if ((seq1 == NULL) || (seq2 == NULL))
        {
            printf("Error reading sequences\n");
            return EXIT_FAILURE;
        }

        // Compute the distance matrices
        int size1 = strlen(seq1);
        int size2 = strlen(seq2);
        int size3 = strlen(seq3);
        int size4 = strlen(seq4);
        double ** distance_matrix1 = computeDTW(seq1, seq2, size1, size2);
        double ** distance_matrix2 = computeDTW(seq1, seq3, size1, size3);
        double ** distance_matrix3 = computeDTW(seq1, seq4, size1, size4);

        // Print the distance information and optimal paths 
        printf("DTW distance 1: %f\n", distance_matrix1[size1][size2]);
        printOptimalPath(distance_matrix1, size1, size2);
        printf("DTW distance 2: %f\n", distance_matrix2[size1][size3]);
        printOptimalPath(distance_matrix2, size1, size3);
        printf("DTW distance 3: %f\n", distance_matrix3[size1][size4]);
        printOptimalPath(distance_matrix3, size1, size4);

        // Free the memory
        freeDistanceMatrix(distance_matrix1, size1+1);
        freeDistanceMatrix(distance_matrix2, size1+1);
        freeDistanceMatrix(distance_matrix3, size1+1);
        free(seq1);
        free(seq2);
        free(seq3);
        free(seq4);
    }
    // else if(strcmp(filetype, "INT") == 0 )
    // {
    //     int ** seq1 = readIntSeq(file1);
    //     int ** seq2 = readIntSeq(file2);
    //     if ((seq1 == NULL) || (seq2 == NULL))
    //     {
    //         return 1;
    //     }
    //     // double distance = computeDTW(seq1, seq2);
    //     // printf("DTW distance: %f\n", distance);
    //     // freeIntSeq(seq1);
    //     // freeIntSeq(seq2);
    // }

    return EXIT_SUCCESS;
}