#ifndef _EDITDISTANCE_H_
#define _EDITDISTANCE_H_

/* "editDistance.c" provided by COMP20003 as per assignment specifications.
 Modified to add a comparison function */

/* Returns the edit distance of two strings
    reference: https://www.geeksforgeeks.org/edit-distance-in-c/ */
int editDistance(char *str1, char *str2, int n, int m);

/* Returns min of 3 integers 
    reference: https://www.geeksforgeeks.org/edit-distance-in-c/ */
int min(int a, int b, int c);

#endif
