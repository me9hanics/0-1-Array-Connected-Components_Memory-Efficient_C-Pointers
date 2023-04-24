#include <stdio.h>
#include <stdlib.h>
#include "cells.h"

/* GetOnes: Makes a list of the cells that contain a 1 */
CellList* GetOnes(int* array, int rows, int cols){
    CellList* head = NULL;
    head = (CellList*) malloc(sizeof(CellList));
    CellList* tail = head;

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){

            if (*((array+i*cols)+j) == 1){
                CellList* temp = (CellList*) malloc(sizeof(CellList));
                temp->current.row = i;
                temp->current.col = j;
                temp->next = NULL;
                tail->next = temp;
                tail = temp;
            }
        }
    }

    return head->next;
}

int AreNeighbours(Cell a, Cell b){
    /*Assuming, that a and b are not the same cells (so either column or row value is different) */
    if ( (a.row == b.row || a.row == b.row + 1 || a.row == b.row - 1 ) && (a.col == b.col || a.col == b.col + 1 || a.col == b.col - 1) ){
        return 1;
    }
    else{
        return 0;
    }
}

IntList* CoupleCellsTogether(CellList* onesList){
    IntList* start = (IntList*) malloc(sizeof(IntList));
    IntList* end = start;
    CellList* i = onesList;
    CellList* j;
    int index = 0;
    int blobBorder = 0;
    start->value = -1; /* first blob from 0 to n has n+1 cells, therefore we must add 1 to it, and we do that by taking away -1 */
    start->next = NULL;

    while(i->next != NULL){
        j = i;
        /*Check only the cells that are not yet in the currently checked blob*/
        for(int k=0; k<(blobBorder-index); k++){
            j = j->next;
        }

        if(j != NULL){
            /* Using j->next instead of just j because the previous cell is simply j this way, which needs to be connected to the upcoming cell (j->next->next) */
            while(j ->next != NULL){
                if (AreNeighbours(i->current, j->next->current)){
                    CellList* moving = j->next;
                    j->next = j->next->next;
                    moving->next = i->next;
                    i->next = moving;
                    blobBorder++;
                }

                j = j->next;
            }


        }
        /* If the index is on the border after the last search, that means that all cells with index bigger than blobBorder
            were not neighboring to any cells up until the blobBorder count. Hence, they must be in different blobs, and
            we can start sorting a new blob*/
        if(index==blobBorder){
            /*Adding a new blob border*/
            IntList* temp = (IntList*) malloc(sizeof(IntList));
            temp->value = blobBorder;
            temp->next = NULL;
            end->next = temp;
            end = temp;
            blobBorder++;
        }
        i = i->next;
        index++;
    }
    if(blobBorder != -1)
    {
        IntList* temp = (IntList*) malloc(sizeof(IntList));
        temp->value = blobBorder;
        temp->next = NULL;
        end->next = temp;
        end = temp; /* This is not necessary, but I like to keep the end pointer at the end of the list */
    }
    return start;
}

int BiggestComponentSize(int *array, int rows, int cols)
{
    int size = 0;
    CellList* onesList;
    IntList* blobBorders;
/* We gather the list of cells containing 1 */
    onesList = GetOnes(array, rows, cols);
/* Now we sort the neighbouring ones together, parsing different blobs. The function returns the list of border indexes */
    blobBorders = CoupleCellsTogether(onesList);

    /*Acquire sizes from the difference*/
    IntList* borderIndex = blobBorders;
    while (borderIndex != NULL)
    {
        /* The size of the blob is the difference between the current border and the previous one */
        if (borderIndex->next != NULL){
            if (borderIndex->next->value - borderIndex->value > size){
                size = borderIndex->next->value - borderIndex->value;
            }
        }
        borderIndex = borderIndex->next;
    }

    /*Free dynamic memory*/
    CellList* p = onesList;
    CellList* q = p;
    while(p != NULL){
        p = p->next;
        free(q);
        q = p;
    }
    if(q != NULL) {
        free(q);
    }

    IntList* r = blobBorders;
    IntList* s = r;

    while(r != NULL){
        r = r->next;
        free(s);
        s = r;
    }
    if(s != NULL) {
        free(s);
    }

    return size;
}


