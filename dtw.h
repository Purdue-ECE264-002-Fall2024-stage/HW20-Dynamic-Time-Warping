// ***
// *** Do NOT modify this file
// ***

#ifndef DTW_H
#define DTW_H

// File reading functions
char * readCharSeq(char * filename);
char ** readStringSeq(char * filename);

// DTW functions
double ** computeDTW(char * seq1, char * seq2, int size1, int size2);
double ** computeStringDTW(char ** seq1, char ** seq2, int size1, int size2);

#endif // DTW_H