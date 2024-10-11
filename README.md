# Dynamic Time Warping

Learning Goals
==============

* Understand how to calculate the distance of two words
* Understand structure and usage of dynamic time warping algorithm
* Read data from a text file
* Print the paths through the accumulated cost matrix

Calculate Dynamic Time Warping Distance
==============
In this assignment, you will learn about a comparison algorithm called Dynamic Time Warping. This algorithm is very popular for comparing sequences of similar data that may be shifted or of uneven lengths. One particular use example is comparing audio waves. YouTube uses a similar algorithm to try and detect copyright infringements on posted videos. You should review the following documents to gain a better understanding.

* https://www.audiolabs-erlangen.de/resources/MIR/FMP/C3/C3S2_DTWbasic.html
* https://en.wikipedia.org/wiki/Dynamic_time_warping
* https://www.youtube.com/watch?v=9GdbMc4CEhE&ab_channel=HermanKamper
* https://medium.com/aimonks/dtwdistance-dynamic-time-warping-distance-81030be0d85c

![image](https://github.com/user-attachments/assets/f61781d5-2f8b-40ee-aaf6-6d87e69310c2)

You will be expected to calculate the accumulated cost matrix for different sequences of characters, integers, and strings. For characters and integers please use the following distance formula:

$ dist = | a - b | $

For string sequences you should use the Levenshtein distance formula. You should already have experience with this algorithm from HW06 but please  review the following algorithm if needed. You will be analyzing several short poems by Robert E. Frost.
![image](https://github.com/user-attachments/assets/01aca60e-dba8-4b4f-9000-f0722bc44072)
More instructions on how to implement this can be accessed through the wikipedia link.
* https://en.wikipedia.org/wiki/Levenshtein_distance


What to Do
==============
Complete the functions in dtw.c and helper.c. You will first want to complete the readCharSeq() and readStringSeq(). You do not need to worry about removing punctuation or string tidying for readStringSeq(). After that is completed, we strongly advise you to complete and verify the computeDTW() function BEFORE working on the computeStringDTW() function. The functionality between the two is very similar but computeStringDTW() is slightly more complex. For computeDTW() please make sure you are computing the ACCUMULATED cost matrix rather than the individual cost matrix as shown in some of the provided articles. After completing the computeDTW() function, you should begin working on printOptimalPath(). This will print the optimal (smallest) path through the accumulated cost matrix. Please note that you MUST follow the order of path checking outlined in the function comments. Some cost matrices may have multiple correct pathways and in order to match the autograder, you must follow the order outlined. You may want to print out the matrix to verify the correctness of your optimal path, though this should not be included in your final submission. You should verify computeDTW() by running
```
make test1
make test2
```
If your computeDTW() function is working, it is recommended that you begin working on computeStringDTW(). You will also need to complete the functions for Levenshtein(), countElements(). Your Levenshtein code from HW06 should be easily applicable to the Levenshtein function in this assignment. You should test your computeStringDTW() code using:
```
make test3
```

Check Memory Leak
=================

Your program must not crash and must not leak memory.  Use Valgrind to check for leaks. You must also complete the freeDistanceArray() function in helper.c. You should run our provided test to check for memory errors.
```
make memory
```

Functions Needed
================
In helper.c:
```
int Levenshtein(const char* str1, const char* str2)

int countElements(char **seq)

void printOptimalPath(double ** accum_cost_matrix, int size1, int size2)

void freeDistanceMatrix(double ** seq, int num_rows)
```

In dtw.c:
```
char * readCharSeq(char * filename)

char ** readStringSeq(char * filename)

double ** computeDTW(char * seq1, char * seq2, int size1, int size2)

double ** computeStringDTW(char ** seq1, char ** seq2, int size1, int size2)
```

WHAT TO SUBMIT
==============

You **must** follow the instructions precisely. Failing to follow
these instructions will likely make you receive zero in this
assignment.  Your score **is determined by your submission**, nothing
else.  The teaching staff is strictly prohibited seeing anything on
your computer for grading.

```
helper.c, dtw.c
```

Upload `hw20.zip`.

