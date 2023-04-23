#include <stdio.h>

#include "cells.h"

int main(void)
{
    int array1[6][5]=
            {
                    {1, 0, 0, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 1, 0, 0},
                    {1, 0, 0, 0, 1}
            };

    int rows1 = 6;
    int cols1 = 5;
    int array2[7][1]=
            {
                    {0},
                    {1},
                    {0},
                    {0},
                    {0},
                    {1},
                    {1}

            };

    int rows2 = 7;
    int cols2 = 1;
    int array3[2][5] =
            {
                    {1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1}
            };
    int rows3 = 2;
    int cols3 = 5;

    int size1 = findLargestBlob((int*)array1, rows1, cols1);
    int size2 = findLargestBlob((int*)array2, rows2, cols2);
    int size3 = findLargestBlob((int*)array3, rows3, cols3);

    printf("Largest blob sizes: %d, %d, %d", size1, size2, size3);
    return 0;
}