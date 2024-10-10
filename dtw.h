// ***
// *** Do NOT modify this file
// ***

#ifndef DTW_H
#define DTW_H

// File reading functions
char * readCharSeq(char * filename);

// DTW functions
double ** computeDTW(char * seq1, char * seq2, int size1, int size2);
double ** computeStringDTW(char ** seq1, char ** seq2, int size1, int size2);

// Helper functions
void printOptimalPath(double ** accum_cost_matrix, int size1, int size2);
void freeDistanceMatrix(double ** seq, int num_rows);

#endif // DTW_H