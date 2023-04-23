#ifndef CELLS_LIBRARY_H
#define CELLS_LIBRARY_H

typedef struct {
    int row;
    int col;
} Cell;

typedef struct CellList{
    struct CellList *next;
    Cell current;
} CellList;

typedef struct IntList{
    struct IntList *next;
    int value;
} IntList;

CellList* GetOnes(int* array, int rows, int cols);
int AreNeighbours(Cell a, Cell b);
IntList* CoupleTogetherCells(CellList* onesList);
int findLargestBlob(int *array, int rows, int cols);


#endif //CELLS_LIBRARY_H
