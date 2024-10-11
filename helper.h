#ifndef HELPER_H
#define HELPER_H

// Helper functions
int Levenshtein(const char* str1, const char* str2);
int countElements(char **seq);
void printOptimalPath(double ** accum_cost_matrix, int size1, int size2);
void freeDistanceMatrix(double ** seq, int num_rows);

#endif // HELPER_H