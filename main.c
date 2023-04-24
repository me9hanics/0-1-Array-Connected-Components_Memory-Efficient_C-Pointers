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

    int size1 = BiggestComponentSize((int*)array1, rows1, cols1);

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

    int size2 = BiggestComponentSize((int*)array2, rows2, cols2);

    int array3[2][5] =
            {
                    {1, 0, 1, 0, 0},
                    {0, 0, 0, 1, 1}
            };
    int rows3 = 2;
    int cols3 = 5;

    int size3 = BiggestComponentSize((int*)array3, rows3, cols3);

    int array4[3][5] =
            {
                    {0, 1, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 1, 1, 0, 0}
            };
    int rows4 = 3;
    int cols4 = 5;

    int size4 = BiggestComponentSize((int*)array4, rows4, cols4);

    int array5[4][6] =
            {
                    {1, 0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 1, 1},
                    {1, 0, 0, 0, 0, 0},
                    {1, 1, 0, 1, 1, 1}
            };
    int rows5 = 4;
    int cols5 = 6;

    int size5 = BiggestComponentSize((int*)array5, rows5, cols5);

    printf("Largest connected component sizes: %d, %d, %d, %d, %d", size1, size2, size3, size4, size5);
    return 0;
}